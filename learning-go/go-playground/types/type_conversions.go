package main

import (
	"fmt"
)

// Animal ...
type Animal struct {
	Name string
}

// NewAnimal ...
func NewAnimal(name string) (Animal, error) {
	return Animal{Name: name}, nil
}

// Cat ...
type Cat struct {
	Name string
}

// Dog ...
type Dog Animal

func main() {
	a, _ := NewAnimal("dido")
	d := Dog{Name: "mido"}
	dog := Animal(d)
	// c := Cat{Name: "gido", Yolo: "tooo"}
	c := Cat{Name: "gido"}
	fmt.Printf("%#v\n", a)
	fmt.Printf("%#v\n", d)
	fmt.Printf("%#v\n", dog)
	fmt.Printf("%#v\n", c)
	cat := Animal(c)
	fmt.Printf("%#v\n", cat)
}
