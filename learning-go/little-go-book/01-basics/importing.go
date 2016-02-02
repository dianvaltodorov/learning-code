package main

import (
  "fmt"
  "os"
)

func main()  {

  if len(os.Args) != 2 {
    os.Exit(1)
  }

  fmt.Println("the program is", os.Args[0])
  fmt.Println("it's over", os.Args[1])
}
