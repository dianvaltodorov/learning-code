class Node:
    def __init__(self):
        self.children = [Node for x in range(26)]
        self.is_ending = False

class Trie:
    def __init__(self):
        self.root = Node()
        self.word = 0

    def insert_word(self, word):
        self._insert_word(word, self.root)

    def _insert_word(self, word, node):
        if word == "":
            node.is_ending = True
        else:
            pos = ord(word[0]) - ord('a')
            if node.edges[pos] is None:
                node.edges[pos] = Node()
                _insert_word_helper(self, word[1:], current_node.edges)

    def search(self, word):
        self._search_helper(word, self.root)

    def _search(self, word, node):
        current_node = node
        previous_node = None
        while current_node is not None and word != "":
            previous_node = current_node
            pos = ord(word[0]) - ord('a')
            current_node = current_node.edges[pos]
            word = word[1:]
        if current_node is None and word == "":
            previous_node.value += 1
            return previous_node.value
        else:
            print "Nothing found"




tr = Trie()
tr.insert_word("dido")
tr.search("ala")
