package main

import "fmt"

func main() {
	var a [4]int
	fmt.Println(a, len(a), cap(a))
	a[0] = 1
	a[2] = 4
	a[1] = 2
	a[3] = 2
	fmt.Printf("type of a is %T, len(a) = %d, cap(a) = %d, a = %v\n", a, len(a), cap(a), a)

	b := [2]string{"Penn", "Teller"}
	fmt.Printf("type of b is %T, len(b) = %d, cap(b) = %d, b = %v\n", b, len(b), cap(b), b)

	c := [...]string{"Penn", "Teller", "Yolo", "Baba", "Jaba"}
	fmt.Printf("type of c is %T, len(c) = %d, cap(c) = %d, c = %v\n", c, len(c), cap(c), c)

	letters := []string{"a", "b", "c", "d"}
	fmt.Printf("type of letters is %T, len(letters) = %d, cap(letters) = %d, c = %v\n", letters, len(letters), cap(letters), letters)
	letters = append(letters, "t", "r", "u", "v", "w", "x", "y", "z")
	fmt.Printf("type of letters is %T, len(letters) = %d, cap(letters) = %d, c = %v\n", letters, len(letters), cap(letters), letters)

	var s []byte
	s = make([]byte, 5, 6)
	// s == []byte{0, 0, 0, 0, 0}
	fmt.Printf("type of s is %T, len(s) = %d, cap(s) = %d, s = %v\n", s, len(s), cap(s), s)
	s = append(s, 3, 2, 4, 1)
	fmt.Printf("type of s is %T, len(s) = %d, cap(s) = %d, s = %v\n", s, len(s), cap(s), s)

	trains := [3]string{"Лайка", "Белка", "Стрелка"}
	trainsSlices := trains[:]
	fmt.Printf("type of trainsSlices is %T, len(trainsSlices) = %d, cap(trainsSlices) = %d, trainsSlices = %v\n", trainsSlices, len(trainsSlices), cap(trainsSlices), trainsSlices)
	trainsSlices = append(trainsSlices, "Борче", "Яйце", "Хляб", "Спам")
	fmt.Printf("type of trainsSlices is %T, len(trainsSlices) = %d, cap(trainsSlices) = %d, trainsSlices = %v\n", trainsSlices, len(trainsSlices), cap(trainsSlices), trainsSlices)

	d := [5]int{1, 2, 4, 9, 5}
	f := d[:]
	f[3] = 100000
	fmt.Printf("type of f is %T, len(f) = %d, cap(f) = %d, f = %v\n", f, len(f), cap(f), f)
	fmt.Printf("type of d is %T, len(d) = %d, cap(d) = %d, d = %v\n", d, len(d), cap(d), d)

	var scores []int
	t := make([]int, len(scores), (cap(scores)+1)*2) // +1 in case cap(s) == 0
	for i := range t {
		t[i] = i
	}
	scores = t
	fmt.Printf("type of scores is %T, len(scores) = %d, cap(scores) = %d, scores = %v\n", scores, len(scores), cap(scores), scores)

}
