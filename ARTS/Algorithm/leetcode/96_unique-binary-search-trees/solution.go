/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19
*/
package main
func numTrees(n int) int {
	m := make([]int, 0, 100)
	m = append(m, 1)
	m = append(m, 1)
	for i := 2; i <= n; i++ {
		cnt := 0
		for j := 1; j <= i; j++ {
			cnt += m[j-1] * m[i-j]
		}
		m = append(m, cnt)
	}
	return m[n]
}
