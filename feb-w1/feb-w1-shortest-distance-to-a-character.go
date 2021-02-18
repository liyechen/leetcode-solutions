package main

func shortestToChar(s string, c byte) []int {
	res := make([]int, len(s))
	if len(s) == 0 {
		return res
	}

	pos := make([]int, 0)
	for idx, v := range s {
		if byte(v) == c {
			pos = append(pos, idx)
		}
	}

	curPos := 0
	first := -len(s) * 2
	second := pos[0]

	for i := 0; i < len(s); i++ {
		p := i - first
		if p > second-i {
			p = second - i
		}
		res[i] = p
		if i == second {
			first = i
			if curPos+1 >= len(pos) {
				second = len(s) * 2
			} else {
				second = pos[curPos+1]
			}
			curPos++
		}
	}

	return res
}
