package main

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	index := 0
loop:
	for ; index < len(strs[0]); index++ {
		for i := 1; i < len(strs); i++ {
			if len(strs[i]) <= index || strs[i][index] != strs[0][index] {
				break loop
			}
		}
	}
	return strs[0][0:index]
}
