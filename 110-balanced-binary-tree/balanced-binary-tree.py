# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def height(root):
    if not root:
        return 0
    left=height(root.left)
    right=height(root.right)
    if left==-1 or right==-1:
        return -1
    diff=abs(right-left)
    return -1 if diff>1 else 1+max(left,right)

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        left=right=0
        right=height(root.right)
        left=height(root.left)
        return False if left==-1 or right==-1 else abs(right-left)<=1