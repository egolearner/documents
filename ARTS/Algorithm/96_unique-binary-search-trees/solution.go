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
