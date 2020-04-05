package main

import "strings"

func getPermutation(n int, k int) string {
	fact := 1
	digits := make([]int, 0, n)
	for i := 1; i <= n; i++ {
		fact *= i
		digits = append(digits, i)
	}

	var sb strings.Builder
	sb.Grow(n)
	k -= 1 // make index work
	for i := n; i >= 1; i-- {
		// XXX 一开始在循环最后更新fact，导致循环结束条件不好写
		fact /= i
		index := k / fact
		sb.WriteRune(rune('0'+digits[index]))
		copy(digits[index:], digits[index+1:])
		digits = digits[:len(digits)-1]
		k -= index * fact
	}
	return sb.String()
}
