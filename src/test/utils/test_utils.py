import os

from iegen.utils import copy_yaml_config_template


def test_config_is_copied():
    cfg_file = os.path.join(os.getcwd(), 'iegen.yaml')
    assert os.path.exists(cfg_file) is False
    copy_yaml_config_template()
    assert os.path.exists(cfg_file) is True
    os.remove(cfg_file)
