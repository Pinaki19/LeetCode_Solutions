# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    allValues=[]
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.allValues.clear()
        self.inOrder(root)
        self.allValues.sort()
        n=len(self.allValues)
        return self.createBST(0,n-1)
    
    def createBST(self,l,r):
        if l>r:
            return None
        if l==r:
            return TreeNode(self.allValues[l])
        mid=l+(r-l)//2
        cur=TreeNode(self.allValues[mid])
        cur.left=self.createBST(l,mid-1)
        cur.right=self.createBST(mid+1,r)
        return cur


    def inOrder(self,root):
        if not root:
            return
        self.inOrder(root.left)
        self.allValues.append(root.val)
        self.inOrder(root.right)