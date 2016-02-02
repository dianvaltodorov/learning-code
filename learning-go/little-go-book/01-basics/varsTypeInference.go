package main

import (
  "fmt"
)

func main() {
  power := 9000 // declare and assign
  fmt.Printf("Is's over %d\n", power)

  // power := 8000 will break
  power = 8000 // only assign
  fmt.Printf("Is's over %d\n", power)

  name, power := "Goku", 100
  fmt.Printf("%s's default power is %d\n", name,  power)

}
