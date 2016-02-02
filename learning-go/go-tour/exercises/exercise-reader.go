package main

import "golang.org/x/tour/reader"

type MyReader struct{}

// TODO: Add a Read([]byte) (int, error) method to MyReader.

func (mr MyReader) Read(x []byte) (int, error) {
	if len(p) == 0 {
		return 0, nil
	}
	if d.err != nil {
		return 0, d.err
	}

}

func main() {
	reader.Validate(MyReader{})
}
