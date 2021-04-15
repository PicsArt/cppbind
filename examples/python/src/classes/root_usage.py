from classes.root_pygen import Root


def create_root():
    # [[root-usage]]
    # create a new root instance
    path = '/path/to/root/'
    root = Root(path)
    assert root.path == path
    # [[root-usage]]
