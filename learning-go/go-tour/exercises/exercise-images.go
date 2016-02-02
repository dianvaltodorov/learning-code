package main

import (
	"image"
	"image/color"

	"golang.org/x/tour/pic"
)

type Image struct{}

func (i Image) ColorModel() color.Model {
	return color.RGBAModel
}
func (i Image) Bounds() image.Rectangle {
	return image.Rect(0, 0, 50, 50)
}
func (i Image) At(x, y int) color.Color {
	return color.RGBA{10, 10, 255, 255}
}

func main() {
	m := Image{}
	pic.ShowImage(m)
}
