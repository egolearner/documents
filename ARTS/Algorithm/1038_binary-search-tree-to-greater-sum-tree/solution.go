package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func rightTraverse(root *TreeNode, rsum int) int {
	if root.Right != nil {
		rsum = rightTraverse(root.Right, rsum)
	}
	rsum += root.Val
	root.Val = rsum
	if root.Left != nil {
		rsum = rightTraverse(root.Left, rsum)
	}
	return rsum
}
func bstToGst(root *TreeNode) *TreeNode {
	rightTraverse(root, 0)
	return root
}
