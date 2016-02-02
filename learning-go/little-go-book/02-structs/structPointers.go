package main

import (
  "fmt"
)

type Saiyan struct {
	Name  string
	Power int
}


func main() {

  goku := &Saiyan{
    Name:  "Goku",
    Power: 9000,
  }

  fmt.Println(goku.Power)
  Super(goku) // modify goku.Power to 19000
  fmt.Println(goku.Power)

  Turbo(goku) // not changed since last time, prints 19000
  fmt.Println(goku.Power)
}

func Super(s *Saiyan) {
	s.Power += 10000
}

func Turbo(s *Saiyan) {
  s = &Saiyan{"Gohan",  1000}
  fmt.Println(s.Power)
}
