import os
import configparser
import json

DEFAULT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../../../config/")
DEFAULT_CONFIG = os.path.join(DEFAULT_CONFIG_DIR, "iegnen_config.cfg")

DEFAULT_CONFIG_DIRS = ['', '~/', './', DEFAULT_CONFIG_DIR]


def load_json_file(x):
    for p in DEFAULT_CONFIG_DIRS:
        file_name = os.path.join(p, x)
        if os.path.isfile(file_name):
            with open(file_name, 'r') as json_file:
                return json.load(json_file)

    return json.load(open(x, 'r'))


def load_json_or_file(x):
    try:
        return load_json_file(x)
    except:
        return json.loads(x)


def read_config(config_file = None):
    """
    creates and loads config file.
    Args:
        config_file: default config file
    """
    config_file = config_file or DEFAULT_CONFIG

    config = configparser.ConfigParser(
        converters={
            'list': lambda x: [i.strip() for i in x.split(',')],
            'json_file': load_json_file,
            'json': lambda x: json.loads(x),
            'json_or_file': load_json_or_file,
        }
    )
    config.read_file(open(config_file))
    return config


class IEG_Config(object):
    """
    Loads IEG config file into structure
    """

    def __init__(self, file_names = None):
        """
        initilizes conifg

        loads default config as well as config provided by user
        Args:
            file_names: list of file names that is going to be loaded
        """
        cnfg = read_config()

        if file_names is not None:
            cnfg.read(file_names)

        self.cnfg = cnfg
        self.defaults = cnfg.defaults()

        # load language parameters
        self.languages = {}
        for lang, v in cnfg.items("LANGUAGE"):
            try:
                self.languages[lang] = load_json_or_file(v)
            except json.decoder.JSONDecodeError as e:
                # TODO: error reporting
                raise e

        self.attributes = cnfg.getjson_or_file("API", "attributes")
        self.source_dir = cnfg.get("PARSER", "source_dir")
        self.api_start_kw = cnfg.get("API", "parser_start")

config = IEG_Config(["~/iegnen_config.cfg", "iegnen_config.cfg"])

