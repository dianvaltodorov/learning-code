package main

import (
  "fmt"
)

type Saiyan struct {
	Name  string
	Power int
}

func NewSaiyan(name string, power int) *Saiyan{
  return &Saiyan {
    Name: name,
    Power: power,
  }
}

func (s *Saiyan) Super(){
  s.Power += 10000
}

func main() {

  goku := &Saiyan{
    Name:  "Goku",
    Power: 9000,
  }

  dido := new(Saiyan)
  dido.Name = "Dido"
  dido.Power = 7431
  fmt.Println(dido.Name)

  foo := Saiyan {}
  foo.Name = "Foo"

  bar := &Saiyan {}
  bar.Name = "Bar"


  fmt.Println(foo.Name)
  fmt.Println(bar.Name)

  fmt.Println(goku.Power)
  goku.Super() // modify goku.Power to 19000
  fmt.Println(goku.Power)

}
