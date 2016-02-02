package main

import "fmt"

// Vertex is a point
type Vertex struct {
	X int
	Y int
}

var (
	v1 = Vertex{1, 2}
	v2 = Vertex{X: 9, Y: 99}
	v3 = Vertex{Y: 1, X: 2}
	v4 = Vertex{Y: 1}
	v5 = Vertex{1, 2}
	p1 = &Vertex{1, 2}
	p2 = &v1
)

// TODO: ask kiro
func main() {
	fmt.Println(
		v1,
		v2,
		v3,
		v4,
		v5,
		p1,
		*p2)
}
