package main

import (
	"sort"
)

func minimumAbsDifference(arr []int) [][]int {
	var result [][]int
	sort.Ints(arr[:])
	min := 100000000
	for i := 1; i < len(arr); i++ {
		diff := arr[i] - arr[i-1]
		if diff < min {
			min = diff
		}
	}
	for i := 1; i < len(arr); i++ {
		diff := arr[i] - arr[i-1]
		if diff == min {
			result = append(result, []int{arr[i-1], arr[i]})
		}
	}
	return result

}
