package main

import (
  "fmt"
)

func main() {
  lookup := make(map[string]int, 2)
  lookup["goku"] = 9001
  lookup["dido"] = 4144
  lookup["yolo"] = 1243
  lookup["mimi"] = 2341
  lookup["sasho"] = 124
  power, exists := lookup["vegeta"]
  fmt.Println(power, exists)
  power, exists = lookup["dido"]
  fmt.Println(power, exists)
  fmt.Println(len(lookup))
  fmt.Println(lookup)

  for key, value := range lookup {
    fmt.Println(key, value)

  }
}
