# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        ans=0

    def process(self,root,cur):
        if not root:
            return
        cur.append(root.val)
        if not root.right and not root.left:
            for i,val in enumerate(reversed(cur)):
                self.ans+=(val<<i)
        self.process(root.left,cur)
        self.process(root.right,cur)
        cur.pop()


        
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        self.process(root,[])
        return self.ans