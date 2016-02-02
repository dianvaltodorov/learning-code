package main

import "fmt"

// Vertex is a point
type Vertex struct {
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{1, 2})
	v := Vertex{1, 2}
	v.X = 10000
	p := &v
	fmt.Println(*p)
	(*p).X = 999
	fmt.Println(v.X)
	p.X = 13
	fmt.Println(v.X)
}
