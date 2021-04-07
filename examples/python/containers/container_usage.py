from containers.containers_pygen import Containers


def using_map_functions():
    containers = Containers()
    containers.add_string_pair(('info1', 'value1'))
    str_map = containers.get_string_map()
    print(str_map['info1'])


