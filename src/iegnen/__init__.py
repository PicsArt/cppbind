import os
import logging as logging
from logging import getLevelName
from iegnen.common.config import config as default_config


log_file = os.path.expanduser(default_config.logging.log_file)
logging.basicConfig(filename=log_file,
                    level=getLevelName(default_config.logging.level))
