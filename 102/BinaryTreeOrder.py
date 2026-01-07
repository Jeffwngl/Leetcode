def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    result = []
    self.levelSearch(root, 0, result)
    return result
    

def levelSearch(self, node, currLevel, result):

    if not node:
        return

    elif len(result) <= currLevel:
        result.append([])
    
    result[currLevel].append(node.val)

    self.levelSearch(node.left, currLevel + 1, result)
    self.levelSearch(node.right, currLevel + 1, result)
