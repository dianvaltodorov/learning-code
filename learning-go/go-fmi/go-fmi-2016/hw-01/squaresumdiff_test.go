package main

import (
	"testing"
)

func TestWithReadmeExample(t *testing.T) {
	var expected uint64 = 2640
	found := SquareSumDifference(10)

	if found != expected {
		t.Errorf("Expected %d but found %d for n=10", expected, found)
	}
}

func testSquareSumDiff(n uint64, expected uint64, t *testing.T) {
	result := SquareSumDifference(n)
	if result != expected {
		t.Error("Expected ", expected, ", got ", result)
	}
}

func TestWithExample(t *testing.T) {
	testSquareSumDiff(10, 2640, t)
}

func TestWithZero(t *testing.T) {
	testSquareSumDiff(0, 0, t)
}

func TestWithSomeReallyBigNumber(t *testing.T) {
	testSquareSumDiff(100, 25164150, t)
}
