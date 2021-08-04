import os

PROJECT_CONFIG_DIR = os.path.join(os.path.dirname(__file__), "../config/")
YAML_CONFIG_TEMPLATE_PATH = os.path.join(PROJECT_CONFIG_DIR, 'iegen.yaml')
JINJA_UNIQUE_MARKER = '~!+marker#@~'
