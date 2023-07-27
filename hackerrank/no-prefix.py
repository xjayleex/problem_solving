def noPrefix(words):
    class Node:
        def __init__(self, value):
            self.value = value
            self.last = False
            self.child = dict()
    class Trie:
        def __init__(self):
            self.head = Node(None)
        def insert(self, string):
            current_node = self.head
            for i, c in enumerate(string):
                if c not in current_node.child:
                    current_node.child[c] = Node(c)
                else: # c in self.child
                    if i == len(string) - 1:
                        print("BAD SET")
                        print(string)
                        return False
                    if current_node.child[c].last:
                        print("BAD SET")
                        print(string)
                        return False
                if i == len(string)-1:
                    current_node.child[c].last = True

                current_node = current_node.child[c]
            return True


    # Write your code here
    #words.sort(key=len)
    trie = Trie()
    for word in words:
        ok = trie.insert(word)
        if not ok:
            break
    if ok :
        print("GOOD SET")

#noPrefix(['aab','aac','aacghgh','aabghgh'])
noPrefix(['abcd', 'abc'])