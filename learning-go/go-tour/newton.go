package main

import (
	"fmt"
)

// Sqrt find the sqrt by the Newton method
func Sqrt(x float64) float64 {
	z := float64(10)
	for i := 0; i < 10; i++ {
		z = z - (z*z-x)/z
	}
	return z
}

func main() {
	fmt.Println(Sqrt(2))
}
