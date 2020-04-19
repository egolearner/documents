package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	sum := 0
	cur := []*TreeNode{root}
	for {
		var next []*TreeNode
		for _, p := range cur {
			if p.Left != nil {
				next = append(next, p.Left)
			}
			if p.Right != nil {
				next = append(next, p.Right)
			}
		}
		if len(next) == 0 {
			for _, p := range cur {
				sum += p.Val
			}
			break
		}
		cur = next
	}
	return sum
}
