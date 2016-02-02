package main

import (
	"fmt"
	"strings"
)

// WordCount tells the number of occurences inside a text
func WordCount(s string) map[string]int {
	var yolo map[string]int
	yolo = make(map[string]int)
	yolo["x"] = 1
	fields := strings.Fields(s)
	fmt.Println(fields)
	for _, field := range fields {
		yolo[field]++
	}
	return yolo
}

func main() {
	fmt.Println(WordCount("foo foo foo  bar fooo yobo tdodo"))

}
