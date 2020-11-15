package main

import "strconv"

func diffWaysToCompute(input string) []int {
	return compute([]rune(input))
}

func compute(input []rune) []int {
	var res []int
	if (len(input) == 1) {
		res = append(res, int(input[0]-'0'))
		return res
	}
	has_punc := false
	// XXX 变量重复，r
	for i, o := range input {
		if o == '+' || o == '-' || o == '*' {
			has_punc = true
			left := compute(input[:i])
			right := compute(input[i+1:])
			for _, l := range left {
				for _, r := range right {
					switch o {
					case '+':
						res = append(res, l+r)
					case '-':
						res = append(res, l-r)
					case '*':
						res = append(res, l*r)
					}
				}
			}
		}
	}
	if !has_punc {
		v, _ := strconv.Atoi(string(input))
		res = append(res, v)
	}
	return res
}
