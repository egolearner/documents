package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, num := range nums {
		to_find := target - num
		if val, ok := m[to_find]; ok {
			return []int{val, i}
		}
		m[num] = i
	}
	return nil
}
