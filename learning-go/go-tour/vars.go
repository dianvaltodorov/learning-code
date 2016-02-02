package main

import "fmt"

var python, java, cpp, foo bool
var k, j int = 3, 4

// Pi is yolo
const Pi = 3.14

const (
	// Big is a huge number by shifting a 1 bit left 100 places.
	// In other words, the binary number that is 1 followed by 100 zeroes.
	Big = 1 << 100
	// Small is 1<<1, or 2.
	Small = Big >> 99
)

func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func main() {
	yolo := 523
	fmt.Println(k, cpp, python, java)
	fmt.Println(j)
	fmt.Println(yolo)

	i := 42
	f := float64(i)
	u := uint(f)
	fmt.Println(i, f, u)

	v := 42.3341 // change me!
	fmt.Printf("v is of type %T\n", v)
	fmt.Printf("v is of type %f\n", Pi)

	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))

}
