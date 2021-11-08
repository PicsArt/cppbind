import cachetools


functions_cache_list = []


# wrapper for cachetools.cached decorator to be to reset all caches
def cached(cache, key=cachetools.keys.hashkey, lock=None):
    def decorator(func):
        cached_func = cachetools.cached(cache, key, lock)(func)
        functions_cache_list.append(cache)

        def wrapper(*args, **kwargs):
            return cached_func(*args, **kwargs)
        return wrapper
    return decorator


def clear_cache():
    global functions_cache_list
    for cache in functions_cache_list:
        cache.clear()
