"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 03/24/2022-13:05.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.typedefs.queue_int_shared as pybind_queue_int_shared_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class QueueIntShared(metaclass=IEGenMetaclass):
    """
    Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L15
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L15>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L22
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L22>`_
        """
        pass
    
    @bind
    def push_back(self, element: int) -> None:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L37
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L37>`_
        """
        pass

    @bind
    def get_size(self) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L46
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L46>`_
        """
        pass


class QueueIntSharedUsage(metaclass=IEGenMetaclass):
    """
    Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L63
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L63>`_
    """
    
    @bind
    def __init__(self, q: QueueIntShared):
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L70
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L70>`_
        """
        pass
    
    @property
    @bind
    def saved_queue(self) -> QueueIntShared:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L127
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L127>`_
        """
        pass

    
    @classmethod
    @bind
    def get_size(cls, q: QueueIntShared) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L77
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L77>`_
        """
        pass

    @classmethod
    @bind
    def get_last_element(cls, q: QueueIntShared) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L86
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L86>`_
        """
        pass

    @classmethod
    @bind
    def get_first_element(cls, q: QueueIntShared) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L95
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L95>`_
        """
        pass

    @classmethod
    @bind
    def get_inv_queue(cls, v: List[int]) -> QueueIntShared:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L104
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L104>`_
        """
        pass

    @bind
    def get_saved_queue(self) -> QueueIntShared:
        """
        Documentation generated from: `cxx/typedefs/queue_int_shared.hpp#L119
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/typedefs/queue_int_shared.hpp#L119>`_
        """
        pass
