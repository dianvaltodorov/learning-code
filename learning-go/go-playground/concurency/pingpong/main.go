package main

import "fmt"

func pinger(c chan string) {
	c <- "ping"
}
func ponger(c1 chan string, c2 chan string) {
	msg := <-c1
	fmt.Println("PONGER GOT", msg)
	c2 <- "pong"
}

func printer(c chan string) {
	fmt.Println(<-c)
}

func main() {
	c1, c2 := make(chan string), make(chan string)
	go ponger(c1, c2)
	go pinger(c1)
	go printer(c2)
	var input string
	fmt.Scanln(&input)
}
