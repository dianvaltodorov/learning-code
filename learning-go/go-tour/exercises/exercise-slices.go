package main

import "golang.org/x/tour/pic"

func Pic(dx, dy int) [][]uint8 {
	p := make([][]uint8, dy)
	for i := 0; i < dy; i++ {
		p[i] = make([]uint8, dx)
		for j := 0; j < dx; j++ {
			p[i][j] = blueScaleV1(i, j)
		}
	}
	return p
}

func blueScaleV1(x, y int) uint8 {
	return uint8((x + y) / 2)
}

func blueScaleV2(x, y int) uint8 {
	return uint8((x * y))
}

func main() {
	pic.Show(Pic)
}
