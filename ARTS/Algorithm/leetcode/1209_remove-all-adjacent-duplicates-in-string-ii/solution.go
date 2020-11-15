package main

func removeDuplicates(s string, k int) string {
	var result []rune
	cur := 'A'
	cur_cnt := 0
	pop_cnt := 0
	deal := func(new_cur rune) {
		if cur_cnt >= k && pop_cnt > 0 {
			result = result[:len(result)-pop_cnt]
			pop_cnt = 0
		}
		cur_cnt %= k
		if cur_cnt > 0 {
			// XXX 忘了减去pop_cnt
			for i := 0; i < cur_cnt-pop_cnt; i++ {
				result = append(result, cur)
			}
		}
		pop_cnt = 0
		for i := len(result) - 1; i >= 0 && result[i] == new_cur; i-- {
			pop_cnt++
		}
		cur_cnt = pop_cnt + 1
		cur = new_cur
	}
	for _, c := range s {
		if c == cur {
			cur_cnt++
		} else {
			deal(c)
		}
	}
	deal('A')
	return string(result)
}
