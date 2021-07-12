import os
import re

from jinja2 import BaseLoader, Environment, StrictUndefined

PROJECT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../config/")
YAML_CONFIG_TEMPLATE_PATH = os.path.join(PROJECT_CONFIG_DIR, 'iegen.yaml')

JINJA_ENV = Environment(loader=BaseLoader(), undefined=StrictUndefined)


# jinja filters
def replace_regex(input_, pattern, repl, count=0):
    return re.sub(pattern, repl, input_, count)


JINJA_ENV.filters['replace_regex'] = replace_regex
