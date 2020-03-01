package main

/**
* Definition for a binary tree node.
 type TreeNode struct {
     Val int
     Left *TreeNode
     Right *TreeNode
 }
*/

func convertBiNodeImpl(root *TreeNode) (*TreeNode, *TreeNode) {
	if root == nil {
		return nil, nil
	}
	ll, lr := convertBiNodeImpl(root.Left)
	rl, rr := convertBiNodeImpl(root.Right)
	left, right := root, root
	if lr != nil {
		lr.Right = root
		root.Left = nil
		left = ll
	}
	if rl != nil {
		root.Right = rl
		right = rr
	}
	return left, right
}
func convertBiNode(root *TreeNode) *TreeNode {
	left, _ := convertBiNodeImpl(root)
	return left
}
