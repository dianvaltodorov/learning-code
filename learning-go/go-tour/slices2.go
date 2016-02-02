package main

import "fmt"

func main() {
	// TODO: ask kiro
	S := []int{1, 2, 3, 4, 4, 6, 6, 3, 2, 1, 14, 3}
	var s []int
	s = S[1:3]
	printSlice(s)
	s = S[:3]
	printSlice(s)
	s = S[6:10]
	printSlice(s)

	var sl []int
	fmt.Println(sl, len(sl), cap(sl))
	if sl == nil {
		fmt.Println("nil!")
	}

	sl = append(sl, 1, 3, 4, 5, 2)
	fmt.Println(sl)

}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
