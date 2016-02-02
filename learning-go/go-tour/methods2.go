package main

import (
	"fmt"
	"math"
)

// Vertex is a point
type Vertex struct {
	X, Y float64
}

// Abs Calculates the abs of a vertex
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// AbsFunc Calculates the abs of a vertex
func AbsFunc(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// Scale Calculates move point
func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// ScaleFunc move point
func ScaleFunc(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func main() {
	v1 := Vertex{3, 4}
	v1.Scale(2)
	ScaleFunc(&v1, 10)

	p1 := &Vertex{4, 3}
	p1.Scale(3)
	ScaleFunc(p1, 8)

	fmt.Println(v1, p1)

	v2 := Vertex{3, 4}
	fmt.Println(v2.Abs())
	fmt.Println(AbsFunc(v2))

	p2 := &Vertex{4, 3}
	fmt.Println(p2.Abs())
	fmt.Println(AbsFunc(*p2))
	fmt.Println(v1, p1)

}
