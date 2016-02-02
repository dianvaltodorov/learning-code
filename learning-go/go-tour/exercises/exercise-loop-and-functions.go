package main

import (
	"fmt"
	"math"
)

const N = 30

func Sqrt(x float64) float64 {
	z := 1.0
	for {
		z = z - (z*z-x)/(2*z)
		if math.Abs(s-z) < 1e-15 {
			break
		}
		s = z
	}
	return s
}

// Reader is the interface that wraps the basic Read method.
type Reader interface {
	Read(p []byte) (n int, err error)
}

// Writer is the interface that wraps the basic Write method.
type Writer interface {
	Write(p []byte) (n int, err error)
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(math.Sqrt(2))
}
