from examples_lib.typedefs import (
    QueueInt,
    QueueIntUsage,
    QueueIntShared,
    QueueIntSharedUsage
)

# test simple cases

q = QueueInt()
q.push_back(1)
q.push_back(2)
q.push_back_from_str("3")

assert QueueIntUsage.get_first_element(q) == 1
assert QueueIntUsage.get_last_element(q) == 3
assert QueueIntUsage.get_first_element(QueueIntUsage.get_inv_queue([1, 2])) == -1
assert QueueIntUsage.get_size(q) == 3

queue_usage_obj = QueueIntUsage(q)
saved_queue = queue_usage_obj.get_saved_queue()
assert QueueIntUsage.get_first_element(saved_queue) == 1
assert QueueIntUsage.get_last_element(saved_queue) == 3
assert queue_usage_obj.saved_queue.get_size() == 3
assert queue_usage_obj.empty_queue.get_size() == 0

# test shared_ref cases

q_shared = QueueIntShared()
q_shared.push_back(1)
q_shared.push_back(2)
q_shared.push_back(3)

assert QueueIntSharedUsage.get_first_element(q_shared) == 1
assert QueueIntSharedUsage.get_last_element(q_shared) == 3
assert QueueIntSharedUsage.get_first_element(QueueIntSharedUsage.get_inv_queue([1, 2])) == -1
assert QueueIntSharedUsage.get_size(q_shared) == 3

queue_shared_usage_obj = QueueIntSharedUsage(q_shared)
saved_queue_shared = queue_shared_usage_obj.get_saved_queue()
assert (QueueIntSharedUsage.get_first_element(saved_queue_shared) == 1)
assert (QueueIntSharedUsage.get_last_element(saved_queue_shared) == 3)
assert (queue_shared_usage_obj.saved_queue.get_size() == 3)

# test template cases

# we have issue with typedefs on template types for linux

# from examples_lib.typedefs import QueueString, QueueUsage
#
# q_string = QueueString()
# q_string.push_back("a")
# q_string.push_back("b")
# q_string.push_back("c")
#
# assert QueueUsage.get_first_element(q_string) == "a"
# assert QueueUsage.get_last_element(q_string) == "c"
# assert QueueUsage.get_first_element(QueueUsage.get_rev_queue(["ab", "cd"])) == "ba"
# assert QueueUsage.get_size(q_string) == 3
#
# queue_string_usage_obj = QueueUsage(q_string)
# saved_queue_string = queue_string_usage_obj.get_saved_queue()
# assert (QueueUsage.get_first_element(saved_queue_string) == "a")
# assert (QueueUsage.get_last_element(saved_queue_string) == "c")
# assert (queue_string_usage_obj.saved_queue.get_size() == 3)
#
