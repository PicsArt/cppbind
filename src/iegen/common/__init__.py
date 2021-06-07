import os
from jinja2 import BaseLoader, Environment, StrictUndefined

PROJECT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../config/")

JINJA_ENV = Environment(loader=BaseLoader(), undefined=StrictUndefined)
