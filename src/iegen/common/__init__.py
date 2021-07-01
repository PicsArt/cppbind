import os
import re

from jinja2 import BaseLoader, Environment, StrictUndefined

PROJECT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../config/")

JINJA_ENV = Environment(loader=BaseLoader(), undefined=StrictUndefined)


# jinja filters
def replace_regex(input_, pattern, repl):
    return re.sub(pattern, repl, input_)


JINJA_ENV.filters['replace_regex'] = replace_regex
