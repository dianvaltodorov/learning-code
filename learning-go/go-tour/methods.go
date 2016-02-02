package main

import (
	"fmt"
	"math"
)

type MyFloat float64

// Vertex is point
type Vertex struct {
	X, Y float64
}

// Abs of a point
func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// Abs is yolo
func Abs(v Vertex) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

// Abs on a float
func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

// Scale the vertex
func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

// Scale the vertex
func Scale(v *Vertex, f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func main() {
	v := Vertex{3, 4}
	fmt.Println(v.Abs())
	fmt.Println(Abs(v))
	f := MyFloat(-math.Sqrt2)
	fmt.Println(f.Abs())

	v.Scale(10)
	fmt.Println(v.Abs())

	Scale(&v, 10)
	fmt.Println(v.Abs())
}
