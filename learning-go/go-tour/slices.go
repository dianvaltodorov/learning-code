package main

import "fmt"

func main() {
	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(primes)
	var s []int
	s = primes[1:4]
	fmt.Println(s)

	names := []string{
		"John",
		"Paul",
		"George",
		"Ringo",
	}
	fmt.Println(names)

	a := names[0:2]
	b := names[1:3]

	fmt.Println(a)
	fmt.Println(b)

	b[0] = "XXX"
	fmt.Println(a, b)
	fmt.Println(names)

	q := []int{1, 2, 3, 4, 5, 2, 13, 4, 1, 24, 4, 2}
	fmt.Println("q =", q)
	fmt.Printf("type of q is %T", primes)

	r := []bool{true, false, true}
	fmt.Println(r)

	slstr := []struct {
		i int
		b bool
	}{
		{2, true},
	}

	fmt.Println(slstr)
}
