func tribonacci(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 || n == 2 {
		return 1
	}
	a, b, c, d := 0, 1 ,1 ,0
	for i := 2; i < n; i++ {
		d = a+b+c
		a, b, c = b, c, d
	}
	return d
}
