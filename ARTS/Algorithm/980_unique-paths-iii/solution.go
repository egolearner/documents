package main

func visit(grid [][]int, dirs [][]int, step, i, j, ccnt int) int {
	cnt := 0
	if grid[i][j] == 2 {
		if step == ccnt {
			return 1
		}
		return 0
	}
	ov := grid[i][j]
	grid[i][j] = 3
	for _, dir := range dirs {
		ni := i + dir[0]
		nj := j + dir[1]
		// XXX dirs -> grid
		// XXX i, j -> ni, nj
		if ni >= 0 && ni < len(grid) && nj >= 0 && nj < len(grid[0]) && (grid[ni][nj] == 0 || grid[ni][nj] == 2) {
			cnt += visit(grid, dirs, step+1, ni, nj, ccnt)
		}
	}
	grid[i][j] = ov
	return cnt
}
func uniquePathsIII(grid [][]int) int {
	ccnt := 0
	bi, bj := 0, 0
	for i, r := range grid {
		for j, v := range r {
			if v != -1 {
				ccnt++
				if v == 1 {
					bi = i
					bj = j
				}
			}
		}
	}
	dirs := [][]int{
		[]int{0, 1},
		[]int{0, -1},
		[]int{1, 0},
		// XXX 1, 1
		[]int{-1, 0},
	}
	return visit(grid, dirs, 1, bi, bj, ccnt)
}
// 4**n, 4**n
// 开始没想到如何判断是否访问全
