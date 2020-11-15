/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package main

func sortedArrayToBST(nums []int) *TreeNode {
	// XXX first submit forget to check
	if len(nums) < 1 {
		return nil
	}
	mid := len(nums) / 2
	node := TreeNode{Val: nums[mid]}
	if mid > 0 {
		node.Left = sortedArrayToBST(nums[0:mid])
	}
	if mid < len(nums)-1 {
		node.Right = sortedArrayToBST(nums[mid+1:])
	}
	return &node
}
