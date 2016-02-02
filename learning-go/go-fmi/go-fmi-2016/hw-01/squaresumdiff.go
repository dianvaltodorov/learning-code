package main

// SquareSumDifference returns the difference between the square of the sum the
// sum of the squares of the first n natural numbers
func SquareSumDifference(n uint64) uint64 {
	return n*(n+1)*(n+2)/4 - n*(n+1)*(n+2)/6
}
