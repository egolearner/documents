/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
	return md(root, 0)
}

func md(root *TreeNode, n int) int {
	if root == nil {
		return n
	}
	lh := md(root.Left, n+1)
	rh := md(root.Right, n+1)
	if lh > rh {
		return lh
	}
	return rh
}
