"""class Node:
    def __init__(self, freq,data):
        self.freq= freq
        self.data=data
        self.left = None
        self.right = None
"""        

# Enter your code here. Read input from STDIN. Print output to STDOUT
def decodeHuff(root, s):
	#Enter Your Code Here
    index = 0
    out = ''
    def _is_leaf(node):
        return node.left is None and node.right is None
    def _goleaf(node, s):
        nonlocal index
        nonlocal out
        if _is_leaf() :
            out += node.data
            return
        if s[index] == '0':
            index += 1
            _goleaf(node.left, s)
        else :
            index += 1
            _goleaf(node.right, s)

        
    while index < len(s) :
        _goleaf(root, s)
    print(out)