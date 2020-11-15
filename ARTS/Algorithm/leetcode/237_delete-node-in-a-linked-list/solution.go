/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// func deleteNode(node *ListNode) {
// 	if node == head {
// 		head = head.Next
// 		return
// 	}
// 	prev := head
// 	cur := head
// 	for cur != nil {
// 		if node == cur {
// 			prev.Next = cur.Next
// 			return
// 		}
// 		cur = cur.Next
// 	}
// }
func deleteNode(node *ListNode) {
	next := node.Next
	for next != nil {
		node.Val = next.Val
		// XXX no if logic
		if next.Next == nil {
			node.Next = nil
			return
		}
		node = next
		next = node.Next
	}
}

// Best Answer:
func deleteNode(node *ListNode) {
    node.Val = node.Next.Val
    node.Next = node.Next.Next
}
