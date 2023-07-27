class Node:
    def __init__(self):
        self.left = None
        self.right = None
        self.info = None

def preOrder(root):
    #Write your code here
    def _dfs(node):
        if node.info is None:
            return
        print(node.info, end=' ')
        if node.left is not None :
            _dfs(node.left)
        if node.right is not None :
            _dfs(node.right)
    _dfs(root)