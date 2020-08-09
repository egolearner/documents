/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeElements(head *ListNode, val int) *ListNode {
	var dummy ListNode
	end := &dummy
	for ; head != nil; head = head.Next {
		if head.Val != val {
			end.Next = head
			end = head
		}
	}
	end.Next = nil
	return dummy.Next
}
