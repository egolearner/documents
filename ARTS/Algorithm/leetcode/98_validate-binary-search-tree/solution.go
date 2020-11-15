/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	if root==nil {
		return true
	}
	ok, _, _ := isValidBSTHelper(root)
	return ok
}

func min(f, s int) int {
	if f < s {
		return f
	}
	return s
}

func max(f, s int) int {
	if f > s {
		return f
	}
	return s
}

func isValidBSTHelper(root *TreeNode) (ok bool, small, big int) {
	small = root.Val
	big = root.Val
	ok = false
	if root.Left != nil {
		lok, lsmall, lbig := isValidBSTHelper(root.Left)
		if !lok || lbig >= root.Val {
			return
		}
		small = min(small, lsmall)
		big = max(lbig, big)
	}
	if root.Right != nil {
		rok, rsmall, rbig := isValidBSTHelper(root.Right)
		if !rok || rsmall <= root.Val {
			return
		}
		small = min(small, rsmall)
		big = max(big, rbig)
	}
	// XXX forget to set ok to true
	ok = true
	return
}
