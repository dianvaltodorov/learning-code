package main

import "fmt"

func one(c1 chan string) {
	msg := <-c1
	fmt.Println(msg)
}

func two(c1 chan string, c2 chan string) {
	c2 <- "Hello from two"
}
func runPiping() {
	c := make(chan string)
	c <- "yolo"
	go one(c)

	var input string
	fmt.Scanln(&input)

}
