package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//  type TreeNode struct {
//      Val int
//      Left *TreeNode
//      Right *TreeNode
//  }
type Range struct {
	begin, end int
}

// func generateRecursive(begin, end int, m *map[Range][]*TreeNode) []*TreeNode {
// 	if val, ok := (*m)[Range{begin, end}]; ok {
// 		return val
// 	}
// 	var arr []*TreeNode
// 	for j := begin; j < end; j++ {
// 		left := generateRecursive(begin, j, m)
// 		right := generateRecursive(j+1, end, m)
// 		for _, lp := range left {
// 			for _, rp := range right {
// 				arr = append(arr, &TreeNode{j, lp, rp})
// 			}
// 		}
// 	}
// 	(*m)[Range{begin, end}] = arr
// 	return arr
// 
// }
// func generateTrees(n int) []*TreeNode {
// 	if n == 0 {
// 		return []*TreeNode{}
// 	}
// 	m := make(map[Range][]*TreeNode)
// 	for i := 1; i <= n+1; i++ {
// 		m[Range{i, i}] = []*TreeNode{nil}
// 	}
// 	return generateRecursive(1, n+1, &m)
// }
func generateTrees(n int) []*TreeNode {
	// XXX 没有判断，题目描述不符，说的是1..n
 	if n == 0 {
 		return []*TreeNode{}
 	}
	// XXX 为啥记忆化dp比普通递归还慢
 	m := make(map[Range][]*TreeNode)
 	for i := 1; i <= n+1; i++ {
 		m[Range{i, i}] = []*TreeNode{nil}
 	}
	for i := 1; i <= n; i++ {
		for step := 1; step <= i; step++ {
			for j := 1; j <= i+1-step; j++ {
				// 左闭右开
				end := j+step
				var arr []*TreeNode
				for k := j; k < end; k++ {
					left := m[Range{j, k}]
					right := m[Range{k+1, end}]
					for _, lp := range left {
						for _, rp := range right {
							arr = append(arr, &TreeNode{k, lp, rp})
						}
					}
				}
				m[Range{j, end}] = arr
			}
		}
	}
	return m[Range{1, n+1}]
}
