package main

import (
	"math"
)

func maxSubArray(nums []int) int {
	return maxSubArrayDevide(nums)
}

func maxSubArrayDP(nums []int) int {
	cur := 0
	max := nums[0]
	for _, num := range nums {
		cur += num
		if cur > max {
			max = cur
		}
		if cur < 0 {
			cur = 0
		}
	}
	return max
}

func maxSubArrayDevide(nums []int) int {
	if len(nums) == 0 {
		return math.MinInt32
	}
	if len(nums) == 1 {
		return nums[0]
	}
	mid := len(nums) / 2

	max := maxSubArrayDevide(nums[0:mid])
	rightMax := maxSubArrayDevide(nums[mid:])
	if max < rightMax {
		max = rightMax
	}
	leftPartMax := math.MinInt32
	leftCur := 0
	rightPartMax := math.MinInt32
	rightCur := 0
	for i := mid - 1; i >= 0; i-- {
		leftCur += nums[i]
		if leftCur > leftPartMax {
			leftPartMax = leftCur
		}
	}
	for i := mid; i < len(nums); i++ {
		rightCur += nums[i]
		if rightCur > rightPartMax {
			rightPartMax = rightCur
		}
	}
	crossMax := leftPartMax + rightPartMax
	if max < crossMax {
		max = crossMax
	}
	return max
}
