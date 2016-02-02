package hello

import "fmt"

const testVersion = 2

// World is function for testing purposes
func World(name string) string {
	// Write some code here to pass the test suite.
	if name == "" {
		return "Hello, World!"
	}
	return fmt.Sprintf("Hello, %s!", name)

}
