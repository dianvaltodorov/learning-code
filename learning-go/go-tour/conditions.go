package main

import (
	"fmt"
	"math"
)

func absValue(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

func main() {
	fmt.Println(
		absValue(4),
		absValue(4),
		pow(4, 3, 10),
		pow(-4, 3, 200),
	)
}
