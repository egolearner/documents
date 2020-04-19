package main
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructMaximumBinaryTree(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	max := nums[0]
	m_i := 0
	for i, n := range(nums) {
		if n > max {
			max = n
			m_i = i
		}
	}
	root := TreeNode{max, constructMaximumBinaryTree(nums[:m_i]), constructMaximumBinaryTree(nums[m_i+1:])}
	return &root
}
