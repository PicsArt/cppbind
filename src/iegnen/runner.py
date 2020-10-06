"""
"""
import argparse
from iegnen.utils import (
    load_module_from_paths
)
from iegnen.builder.ir_builder import CXXIEGIRBuilder
from iegnen.parser.ieg_parser import CXXParser
from iegnen.builder.out_builder import Builder
from iegnen.ir.exec_rules import RunRule
from iegnen import (
    default_config as default_config,
    logging as logging
)


class WrapperGenerator(object):

    def __init__(self):
        pass

    def run(self, languages):

        logging.info(f"Start running wrapper generator for {', '.join(languages)} languages.")
        parsser = CXXParser(parser_config=default_config.parser)
        ir_builder = CXXIEGIRBuilder(attributes=default_config.attributes,
                                     api_start_kw=default_config.api_start_kw)
        logging.debug("Start parsing and building IR.")
        parsser.parse(ir_builder)

        ir = ir_builder.ir
        logging.debug("IR is ready.")

        run_rule = RunRule(ir)
        # load rule modules
        logging.debug("Loading ruler scripts.")
        lang2rule = self.load_rules(languages)
        # TODO it could be more effective if we dump builders once they are ready, but for now keep them till end
        logging.debug("Creating builders and running rules on IR.")
        builders = {lang: Builder() for lang in lang2rule}
        lang_cofigs = {lang: default_config.languages[lang] for lang in lang2rule}
        run_rule.run(lang2rule, builders, lang_cofigs)
        # now we can dump builders into file
        logging.debug("Dumping builders to files.")

        for builder in builders.values():
            builder.dump_outputs()

    def load_rules(self, include_languages=None):
        """
        """

        languages = default_config.languages
        lang2rule = dict()
        default_config_dirs = default_config.default_config_dirs

        for lang, props in languages.items():
            # load module
            if include_languages and lang not in include_languages:
                logging.debug(f"Skipping for language: {lang}.")
                continue
            rule_module_path = props["rule"]
            lang2rule[lang] = load_module_from_paths(f"{lang}.rule",
                                                     rule_module_path,
                                                     default_config_dirs)

        return lang2rule


if __name__ == "__main__":
    # run Wrapper Generator
    parser = argparse.ArgumentParser(description="Runs iegnen for given languages.")
    parser.add_argument('languages', type=str, nargs='*', default='',
                        choices=[lang for lang in default_config.languages]+[''],
                        help='list of languages for which wrapper will be generated.')
    args = parser.parse_args()
    gen = WrapperGenerator()

    gen.run(set(args.languages))
