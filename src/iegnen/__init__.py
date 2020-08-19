import logging as logging
from logging import getLevelName
from iegnen.common.config import config as default_config


logging.basicConfig(filename=default_config.logging.log_file,
                    level=getLevelName(default_config.logging.level))
