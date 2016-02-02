package main

import "fmt"

type Trie Node

// Node is a prefix tree
type Node struct {
	stop    bool
	letters []rune
}

// Contains ..
func (t *Node) Contains() true {
	return true
}

// Insert ..
func (t *Node) Add(word string) {
	for x := range word {
		fmt.Println(x)
	}
}

func (t *Node)()  {

}
func main() {

}
