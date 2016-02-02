package parsePath

import "testing"

var parsePathTests = []struct {
	path       string
	parsedPath string
}{
	{`A/go/..`, `A`},
	{`../B/go/..`, `B`},
	{`D/go/code/../src/warcluster/tests/first/../../`, `/D/go/src/warcluster/`},
	{`D/go/code/../src/warcluster/tests/first/../../`, `/D/go/src/warcluster/`},
	{`/python/movies/episode1/../../lectures/lecture1/examples/../code/../../../mostImportant/MonthyPython/quotes/..`, `/python/mostImportant/MonthyPython/`},
}

func TestParsePath(t *testing.T) {
	for _, tt := range parsePathTests {
		res := parsePath(tt.path)
		if res != tt.parsedPath {
			t.Errorf("parsePath(%q) => %q, want %q", tt.path, res, tt.parsedPath)
		}
	}
}
