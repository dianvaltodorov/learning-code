package main

import (
  "fmt"
)

func main() {
  var power int
  fmt.Printf("Before: It's over %d\n", power)
  power = 9000
  fmt.Printf("After: It's over %d\n", power)

  happy := 1000
  fmt.Printf("I am %d points happy\n", happy)

  swag := getSwag()
  fmt.Println("The returned swag is", swag)


}

func getSwag() int {
  return 100000
}
