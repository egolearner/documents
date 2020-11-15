/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	slow := head
	fast := head
	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	prev := head
	for fast != nil {
		fast = fast.Next
		// XXX :=
		prev = slow
		slow = slow.Next
	}
	if slow == head {
		return head.Next
	}
	prev.Next = slow.Next
	return head
}
