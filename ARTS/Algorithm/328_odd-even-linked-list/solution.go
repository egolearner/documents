package main
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	var odd, even ListNode
	oddLast := &odd
	evenLast := &even
	i := 0
	for head != nil {
		i += 1
		if i % 2 == 1 {
			oddLast.Next = head
			oddLast = head
		} else {
			evenLast.Next = head
			evenLast = head
		}
		head = head.Next
	}
	evenLast.Next = nil
	oddLast.Next = even.Next
	return odd.Next
}
