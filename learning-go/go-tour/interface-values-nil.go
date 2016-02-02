package main

import "fmt"

type I interface {
	M()
	L()
}
type T struct {
	S string
}

func (t *T) M() {
	if t == nil {
		fmt.Println("<nil>")
		return
	}
	fmt.Println(t.S)
}

func (t *T) L() {
	fmt.Println(t.S)
}

func main() {
	var i I

	fmt.Println("YOLOOO")
	describe(i)
	// i.L()

	var t *T

	i = t
	describe(i)
	i.M()

	i = &T{"hello"}
	describe(i)
	i.M()
}

func describe(i I) {
	fmt.Printf("(%v, %T)\n", i, i)
}
