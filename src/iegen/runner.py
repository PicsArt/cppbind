import argparse
import os
import sys

from iegen import default_config, logging
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.builder.out_builder import Builder
from iegen.common.error import Error
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.exec_rules import RunRule
from iegen.parser.ieg_parser import CXXParser
from iegen.utils import (
    clear_iegen_generated_files,
    get_host_platform,
    load_rule_module
)


class WrapperGenerator(object):

    def __init__(self):
        pass

    @staticmethod
    def run(plat_lang_options):

        logging.info(
            f"Start running wrapper generator for {', '.join(list(map(lambda x: x[0] + '.' + x[1], plat_lang_options)))} options.")
        for plat, lang in plat_lang_options:
            WrapperGenerator.run_for(plat, lang)

    @staticmethod
    def run_for(platform, language):
        logging.info(f"Start running wrapper generator for {language} language for {platform} platform.")
        parser = CXXParser()

        ctx_desc = ContextDescriptor(getattr(default_config.application, 'context_def_glob', None), platform, language)
        ctx_mgr = ContextManager(ctx_desc)
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        root_ctx = ir_builder.start_root()

        logging.debug("Start parsing and building IR.")
        parser.parse(ir_builder, **root_ctx)

        ir_builder.end_root()

        if Error.has_error:
            raise Exception('Wrong attribute usage')

        ir = ir_builder.ir
        logging.debug("IR is ready.")

        run_rule = RunRule(ir, ctx_desc, platform, language)
        # load rule modules
        logging.debug("Loading ruler scripts.")
        lang_rule = load_rule_module(language, default_config.application.rule, default_config.default_config_dirs)
        logging.debug("Creating builders and running rules on IR.")
        builder = Builder()
        run_rule.run(lang_rule, builder)
        # now we can dump builders into file
        logging.debug("Dumping builders to files.")

        builder.dump_outputs()


def run(args):
    plat_lang_options = []
    for option in args.languages:
        if '.' in option:
            plat, lang = option.split('.')
        else:
            plat, lang = get_host_platform(), option
        plat_lang_options.append((plat, lang))

    try:
        WrapperGenerator.run(set(plat_lang_options))
    except Exception as e:
        Error.error(e)
        exit(1)


def clean(args):
    if not os.path.isdir(args.dir):
        raise ValueError(f'{args.dir} is not a valid directory.')
    clear_iegen_generated_files(args.dir)


def run_package():
    # run Wrapper Generator
    parser = argparse.ArgumentParser(description="Runs iegen for given languages.")
    choices = [lang for lang in default_config.languages] + \
              [plat + '.' + lang for plat in default_config.platforms for lang in default_config.languages]

    sub_parser = parser.add_subparsers(required=True)

    run_parser = sub_parser.add_parser('run', help='Run iegen to generate code for given languages.')
    run_parser.add_argument('languages', type=str, nargs='+',
                            choices=choices,
                            help='list of languages for which wrapper will be generated.')
    run_parser.set_defaults(func=run)

    clean_parser = sub_parser.add_parser('clean', help='Clean all iegen generated files from directory.')
    clean_parser.add_argument('dir', help='Directory from where all iegen generated files will be deleted.')
    clean_parser.set_defaults(func=clean)

    # print help if nothing is passed
    args = parser.parse_args(args=None if sys.argv[1:] else ['--help'])
    args.func(args)


if __name__ == "__main__":
    run_package()
