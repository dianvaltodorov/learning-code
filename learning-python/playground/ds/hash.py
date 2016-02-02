HASH_TABLE_SIZE = 100


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class HashTable:
    def __init__(self):
        self.table = [[] for i in range(HASH_TABLE_SIZE)]

    def put(self, key, value):
        pos = hash_function(key)
        table[pos].insert(Node(key, value))

    def get(self, key, value):
        pos = hash_function(key)
        return table[pos]

    def search(self, key):
        pos = hash_function(key)
        for node in table[i]:
            if node.key = key:
                return node.value
        return None

    def _hash_function(key):
        return key % HASH_TABLE_SIZE

    def delete(key):
        while
