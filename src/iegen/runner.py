"""
"""
import argparse
from iegen.utils import (
    load_module_from_paths
)
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.parser.ieg_parser import CXXParser
from iegen.builder.out_builder import Builder
from iegen.ir.exec_rules import RunRule
from iegen import (
    default_config as default_config,
    logging as logging
)


class WrapperGenerator(object):

    def __init__(self):
        pass

    def run(self, languages):

        logging.info(f"Start running wrapper generator for {', '.join(languages)} languages.")
        for lang in languages:
            self.run_for(lang)

    def run_for(self, language):

        default_config_dirs = default_config.default_config_dirs
        logging.info(f"Start running wrapper generator for {language} language.")
        lang_config = default_config.languages[language]
        parser = CXXParser(parser_config=lang_config)
        ir_builder = CXXIEGIRBuilder(attributes=default_config.attributes,
                                     api_start_kw=default_config.api_start_kw,
                                     parser_config=parser.config)

        logging.debug("Start parsing and building IR.")
        parser.parse(ir_builder)

        ir = ir_builder.ir
        logging.debug("IR is ready.")

        run_rule = RunRule(ir, language, lang_config)
        # load rule modules
        logging.debug("Loading ruler scripts.")
        lang_rule = load_module_from_paths(f"{language}.rule",
                                           lang_config.rule,
                                           default_config_dirs)
        logging.debug("Creating builders and running rules on IR.")
        builder = Builder()
        run_rule.run(lang_rule, builder)
        # now we can dump builders into file
        logging.debug("Dumping builders to files.")

        builder.dump_outputs()


def run_package():
    # run Wrapper Generator
    parser = argparse.ArgumentParser(description="Runs iegen for given languages.")
    parser.add_argument('languages', type=str, nargs='+',
                        choices=[lang for lang in default_config.languages],
                        help='list of languages for which wrapper will be generated.')
    args = parser.parse_args()
    gen = WrapperGenerator()

    gen.run(set(args.languages))


if __name__ == "__main__":
    run_package()
