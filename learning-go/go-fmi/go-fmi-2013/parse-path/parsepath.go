package parsePath

import (
	"fmt"
	"strings"
)

const (
	sep       = "/"
	parentDir = ".."
)

func parsePath(path string) string {
	dirs := strings.Split(path, sep)
	res := make([]string, len(dirs))
	idx := 0
	for _, d := range dirs {
		if d == parentDir {
			idx -= 1
		} else {
			res[idx] = d
			idx += 1
		}
	}
	res = res[:idx]
	fmt.Println(res)
	return sep + strings.Join(res, sep) + sep
}
