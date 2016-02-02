package main

import (
  "fmt"
)

type Saiyan struct {
	Name  string
	Power int
}

func main() {
	goku := Saiyan{
		Name:  "Goku",
		Power: 90000,
	}
  show(goku)

	dido := Saiyan{
		Name:  "Dido",
		Power: 10000000000,
	}
  show(dido)

	foo := Saiyan{}
  show(foo)

	bar := Saiyan{Name: "Bar"}
	bar.Power = 10000
  show(bar)

	joo := Saiyan{"Joo", 50000}
  show(joo)
}

func show(s Saiyan){
  fmt.Printf("%s power leve is %d\n", s.Name, s.Power)
}
