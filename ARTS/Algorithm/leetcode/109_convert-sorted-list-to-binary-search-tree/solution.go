/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
package main

func findMid(head, tail *ListNode) *ListNode {
	slow := head
	fast := head
	// XXX first run compare to nil
	for fast != tail && fast.Next != tail {
		slow = slow.Next
		fast = fast.Next.Next
	}
	return slow
}
func sortedListToBSTHelper(head, tail *ListNode) *TreeNode {
	if head == tail {
		return nil
	}
	mid := findMid(head, tail)
	node := TreeNode{Val: mid.Val}
	if mid != head {
		node.Left = sortedListToBSTHelper(head, mid)
	}
	if mid.Next != tail {
		node.Right = sortedListToBSTHelper(mid.Next, tail)
	}
	return &node
}
func sortedListToBST(head *ListNode) *TreeNode {
	return sortedListToBSTHelper(head, nil)
}
