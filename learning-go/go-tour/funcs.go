package main

import "fmt"

func add(a, b int) int {
	return a + b
}

func mul(a int, b int) int {
	return a * b
}

func swap(x, y string) (string, string) {
	return y, x
}

func split(sum int) (x, y int) {
	x = sum*123 - 3
	y = sum*141 + 23
	return
}

func main() {
	fmt.Printf("%d + %d = %d\n", 3, 4, add(3, 4))
	fmt.Printf("%d * %d = %d\n", 3, 4, mul(3, 4))
	fmt.Println(split(123))
}
