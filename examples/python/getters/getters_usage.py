from getters.getter_pygen import GetterSetter


def using_map_functions():
    gs = GetterSetter()
    gs.value = 'new value'
    print(gs.value)
