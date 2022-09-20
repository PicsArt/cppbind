import importlib

# a function to test custom helpers
def validate_default_helper_module():
    try:
        importlib.import_module('cppbind_helper')
    except ModuleNotFoundError:
        assert False, 'Default helper module is not available'
