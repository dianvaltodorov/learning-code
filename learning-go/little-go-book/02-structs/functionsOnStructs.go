package main

import (
  "fmt"
)

type Saiyan struct {
	Name  string
	Power int
}

func (s *Saiyan) Super(){
  s.Power += 10000
}

func main() {

  goku := &Saiyan{
    Name:  "Goku",
    Power: 9000,
  }

  fmt.Println(goku.Power)
  goku.Super() // modify goku.Power to 19000
  fmt.Println(goku.Power)

}
