package main

func maxArea(height []int) int {
	res := 0
	length := len(height)
	if length <= 1 {
		return res
	}
	first := 0
	last := length - 1
	for last > first {
		distance := last - first
		h := height[first]
		if height[last] < h {
			h = height[last]
		}
		area := distance * h
		if area > res {
			res = area
		}
		if height[last] < height[first] {
			last--
		} else {
			first++
		}
	}
	return res
}
