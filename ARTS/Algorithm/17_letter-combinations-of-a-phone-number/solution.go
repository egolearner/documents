package main

func recur(m []string, digits *string, index int, result []string, cur []rune) []string {
	if index == len(*digits) {
		// should update slice
		result = append(result, string(cur))
		return result
	}
	candi := m[int((*digits)[index]-'2')]
	for _, c := range candi {
		cur = append(cur, c)
		result = recur(m, digits, index+1, result, cur)
		cur = cur[:len(cur)-1]
	}
	return result
}
func letterCombinations(digits string) []string {
	// XXX invalid check
	if len(digits) == 0 {
		return []string{}
	}
	m := []string{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
	length := 1
	for _, d := range digits {
		length *= len(m[int(d-'2')])
	}
	// XXX make 0-length slice with capacity
	result := make([]string, 0, length)
	cur := make([]rune, 0, len(digits))
	return recur(m, &digits, 0, result, cur)
}
