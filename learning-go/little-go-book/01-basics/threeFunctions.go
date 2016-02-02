package main


func main() {
  _, exists := power("goku")
  if exists == false {
    //handle error
  }
}

func log(message string)  {

}

func add(a int, b int) int {
  return a + b
}

func multiply(a, b int) int {
  return a * b
}

func power(name string) (int, bool){
  return 4, true
}
