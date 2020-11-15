package main

import (
	"strconv"
)

func calPoints(ops []string) int {
	s := make([]int, 1001)
	for _, op := range ops {
		switch op {
		case "C":
			s = s[:len(s)-1]
		case "D":
			s = append(s, s[len(s)-1]*2)
		case "+":
			s = append(s, s[len(s)-1]+s[len(s)-2])
		default:
			value, _ := strconv.Atoi(op)
			s = append(s, value)
		}
	}
	sum := 0
	for _, v := range s {
		sum += v
	}
	return sum
}
