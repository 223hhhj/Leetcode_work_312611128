# Leetcode 460 - LFU Cache
# 312611128 謝佳鴻
class Node:
    def __init__(self, key=0, value=0):
        self.key = key
        self.value = value
        self.freq = 1  # 使用頻率，初始為 1
        self.prev = None  # 雙向鏈表的上下節點
        self.next = None

class DLinkedList:
    def __init__(self):
        self.head = Node()  # 虛擬頭節點
        self.tail = Node()  # 虛擬尾節點
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0

    def add_node(self, node):
        # 加到頭節點後面（新使用的放前面）
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
        self.size += 1

    def remove_node(self, node):
        # 移除指定節點
        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1

    def pop_tail(self):
        # 移除並回傳尾巴前的節點（最舊的）
        if self.size == 0:
            return None
        node = self.tail.prev
        self.remove_node(node)
        return node

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity  # 快取容量
        self.size = 0  # 當前快取中的元素數量
        self.min_freq = 0  # 當前最小頻率
        self.key_to_node = {}  # 存 key 到節點的映射
        self.freq_to_list = {}  # 存頻率到雙向鏈表的映射

    def get(self, key: int) -> int:
        # 如果 key 不存在，回傳 -1
        if key not in self.key_to_node:
            return -1
        
        # 找到對應的節點，更新頻率並回傳 value
        node = self.key_to_node[key]
        self._update_freq(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        # 如果容量為 0，直接返回
        if self.capacity == 0:
            return

        # 如果 key 已存在，更新 value 並調整頻率
        if key in self.key_to_node:
            node = self.key_to_node[key]
            node.value = value
            self._update_freq(node)
            return

        # 如果容量滿了，移除最小頻率的元素
        if self.size >= self.capacity:
            min_list = self.freq_to_list[self.min_freq]
            old_node = min_list.pop_tail()
            del self.key_to_node[old_node.key]
            self.size -= 1
            # 如果最小頻率的列表空了，移除它
            if min_list.size == 0:
                del self.freq_to_list[self.min_freq]

        # 新增新節點
        new_node = Node(key, value)
        self.key_to_node[key] = new_node
        # 如果頻率 1 的列表不存在，創建一個
        if 1 not in self.freq_to_list:
            self.freq_to_list[1] = DLinkedList()
        self.freq_to_list[1].add_node(new_node)
        self.size += 1
        self.min_freq = 1  # 新增的元素頻率為 1，設為最小頻率

    def _update_freq(self, node):
        # 從舊頻率列表移除節點
        old_freq = node.freq
        self.freq_to_list[old_freq].remove_node(node)
        # 如果舊頻率列表空了且是當前最小頻率，min_freq 增加
        if self.freq_to_list[old_freq].size == 0 and old_freq == self.min_freq:
            self.min_freq += 1
            del self.freq_to_list[old_freq]

        # 增加節點頻率並加入新頻率列表
        node.freq += 1
        if node.freq not in self.freq_to_list:
            self.freq_to_list[node.freq] = DLinkedList()
        self.freq_to_list[node.freq].add_node(node)

# 測試程式碼
cache = LFUCache(2)
cache.put(1, 1)  # cache = {1=1}
cache.put(2, 2)  # cache = {1=1, 2=2}
print(cache.get(1))  # 回傳 1
cache.put(3, 3)  # 移除 key=2, cache = {1=1, 3=3}
print(cache.get(2))  # 回傳 -1
print(cache.get(3))  # 回傳 3
cache.put(4, 4)  # 移除 key=1, cache = {3=3, 4=4}
print(cache.get(1))  # 回傳 -1
print(cache.get(3))  # 回傳 3
print(cache.get(4))  # 回傳 4