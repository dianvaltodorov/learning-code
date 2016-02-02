package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a)
	fmt.Println(a[0], a[1])
	primes := [6]int{2, 3, 4}
	fmt.Println(primes)

	var scores [10]int
	scores[1] = 1
	scores[8] = 1
	fmt.Println(scores)
}
