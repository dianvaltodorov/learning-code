package main

import "fmt"

// Vertex is geological part
type Vertex struct {
	Lat, Long float64
}

var m1 map[string]Vertex

func main() {
	m1 = make(map[string]Vertex)

	m1["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	m1["U doma"] = Vertex{
		40.68433, -4.39967,
	}
	m1["Fmi"] = Vertex{
		50.68433, -4.39967,
	}
	m1["Uber office"] = Vertex{
		24.64233, 27.39967,
	}
	m1["Foo"] = Vertex{
		95.68433, -34.39967,
	}

	var m2 = map[string]Vertex{
		"yolo": Vertex{
			95.68433, -34.39967,
		},
	}

	var m3 = map[string]Vertex{
		"yolo": {95.68433, -34.39967},
	}

	fmt.Println(m1["Bell Labs"])
	fmt.Println(m1)
	fmt.Println(m2)
	fmt.Println(m3)

	elem, ok := m1["Foo"]
	if ok {
		fmt.Println(elem)
	}

	elem, ok = m1["Roo"]
	if ok {
		fmt.Println(elem)
	} else {
		fmt.Println("Not found")
	}

}
