# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


from cppbind.common.error import Error


def allowed_after_build(method):
    """Decorator to check that the method/property is not called before IR is built"""

    def wrapper(self, *args, **kwargs):
        if not self.root._is_built():
            Error.internal(f"IR is not completely built. Access to '{method.__name__}' property is forbidden")

        return method(self, *args, **kwargs)

    return wrapper


def available_on(*allowed_cursor_kinds):
    """Decorator to check that the method is called only for cursors with an allowed kind"""

    def decorator(method):

        def wrapper(self, *args, **kwargs):
            # for differentiating between Node and Context methods/properties
            kind = self.kind if hasattr(self, 'kind') else self.node.kind

            if kind not in allowed_cursor_kinds:
                raise AttributeError(f"{self.__class__.__name__}.{method.__name__} is "
                                     f"invalid for {kind} node kind.")

            return method(self, *args, **kwargs)

        return wrapper

    return decorator
