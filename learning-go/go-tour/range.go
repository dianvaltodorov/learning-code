package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
	for i, value := range pow {
		fmt.Println(i, value)
	}

	for i := range pow {
		fmt.Println(i)
	}

	for _, value := range pow {
		fmt.Println(value)
	}
}
