package main

import (
  "fmt"
)

func main() {
  swag := []int {1,2,3,4,2,1,199,1,231,312,41,24,12,4,124,12,412}
  fmt.Println(swag)

  foo := make([]int, 0, 10)
  foo = append(foo, 5) // new array created
  fmt.Println(foo)

  bar := make([]int, 0, 10) //set length
  bar = bar[0:8] // resizing
  bar[7]=134
  fmt.Println(bar)


  items := make([]int, 0, 5)
  c := cap(items)
  l := len(items)
  fmt.Println("items:", items)
  fmt.Println("capacity of items:", c)
  fmt.Println("length of items:", l)

  for i := 0; i  < 25; i++ {
    items = append(items, i)

    if cap(items) != c {
      c = cap(items)
      l = len(items)
      fmt.Println("new capacity:", c)
      fmt.Println("new length:", l)
    }
  }

  fly := make([]int, 5)
  fly = append(fly, 123)
  fmt.Println(fly)

  ss := make([]int, 10)
  fmt.Println(ss)

  powers1 := make([]int, 10)
  for index, _ := range ss{
    powers1[index] = index
  }
  fmt.Println(powers1)

  powers2 := make([]int, 0, 10)
  for index, _ := range ss{
    powers2 = append(powers2, index)
  }
  fmt.Println(powers2)
}
