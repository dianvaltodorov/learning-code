package main

import (
  "fmt"
)

func main() {
  var scores [10]int
  scores[0] = 333

  fmt.Println(scores[0])
  fmt.Println(scores[1])
  fmt.Println(scores[9])

  points := [4]int{123, 123, 434, 5321}
  fmt.Println(points[0])
  fmt.Println(points[1])
  fmt.Println(points[3])

  for index, value := range scores {
    fmt.Printf("%d, %d\n", index, value)
  }
}
