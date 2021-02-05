package main

func findLHS(nums []int) int {
	count := 0

	hashCount := make(map[int]int)
	for _, v := range nums {
		if c, ok := hashCount[v]; ok {
			hashCount[v] = c + 1
		} else {
			hashCount[v] = 1
		}
	}

	for _, v := range nums {
		if c, ok := hashCount[v]; ok {
			if cMinus, ok := hashCount[v-1]; ok {
				if count < c+cMinus {
					count = c + cMinus
				}
			}
			if cPlus, ok := hashCount[v+1]; ok {
				if count < c+cPlus {
					count = c + cPlus
				}
			}
		}
	}

	return count
}
