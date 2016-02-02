package main

import (
	"fmt"
	"regexp"
)

func main() {
	// r, _ := regexp.Compile("p[a-z]*ch")
	//
	// fmt.Println("===MatchString===")
	// fmt.Println(r.MatchString("peach"))
	// fmt.Println(r.MatchString("alabala"))
	// fmt.Println(r.MatchString("peach punch"))
	//
	// fmt.Println("===Find String===")
	// fmt.Println(r.FindString("peach punch pich"))
	// fmt.Println(r.FindString("olio"))
	//
	// fmt.Println("===Find String Index===")
	// fmt.Println(r.FindStringIndex("peach punch parrot pouuch"))
	// fmt.Println(r.FindStringSubmatchIndex("peach punch parrot pouuch"))
	//
	// fmt.Println("===Find String Index===")
	// fmt.Println(r.FindAllString("peach punch pinch", 1))
	//
	// fmt.Println("===Find All String Index===")
	// fmt.Println(r.FindAllStringIndex("peach punch pinch", -1))
	//
	// fmt.Println(r.ReplaceAllString("a peach yolo baba", "<fruit>"))

	ipr, _ := regexp.Compile(`^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$`)
	fmt.Println("===MatchString===")
	fmt.Println(ipr.MatchString("12.34.30.12 l;sdkmg 12.3.1.2 sad 12. 123"))
	fmt.Println(ipr.MatchString("12.3.1.2"))
	fmt.Println(ipr.MatchString("peach punch"))

	fmt.Println("===Find All String Index===")
	fmt.Println(ipr.FindAllStringSubmatch("12.34.30.12 l;sdkmg 12.3.1.2 sad 12. 123", -1))
}
