package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 100; i++ {
		sum += i
	}
	fmt.Printf("sum = %d\n", sum)

	eggs := 1
	for eggs < 100 {
		eggs = eggs + eggs
	}
	fmt.Printf("eggs = %d\n", eggs)
}
