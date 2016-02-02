package main

import "fmt"

func main() {
	i, j, k, l := 12, 3, 23, 52
	pi := &i
	pj := &j
	pk := &k
	pl := &l
	fmt.Println(&i)
	fmt.Printf("%T", i)
	fmt.Println(&j)
	fmt.Println(&k)
	fmt.Println(&l)
	fmt.Println(pi)
	fmt.Println(pj)
	fmt.Println(pk)
	fmt.Println(pl)
}
