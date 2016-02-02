package log

import "testing"

var logTests = []struct {
	log    string
	column uint8
	out    string
}{
	{"2015-08-23 12:37:03 8.8.8.8 As far as we can tell this is a DNS", 0, "2015-08-23 12:37:03"},
	{"2015-08-23 12:37:04 8.8.4.4 Yet another DNS, how quaint!", 0, "2015-08-23 12:37:04"},
	{"2015-08-23 12:37:05 208.122.23.23 There is definitely some trend here", 0, "2015-08-23 12:37:05"},
	{"2015-08-23 12:37:03 8.8.8.8 As far as we can tell this is a DNS", 1, "8.8.8.8"},
	{"2015-08-23 12:37:04 8.8.4.4 Yet another DNS, how quaint!", 1, "8.8.4.4"},
	{"2015-08-23 12:37:05 208.122.23.23 There is definitely some trend here", 1, "208.122.23.23"},
	{"2015-08-23 12:37:03 8.8.8.8 As far as we can tell this is a DNS", 2, "As far as we can tell this is a DNS"},
	{"2025-08-23 12:37:04 8.8.4.4 Yet another DNS, how quaint!", 2, "Yet another DNS, how quaint!"},
	{"2015-08-23 12:37:05 208.122.23.23 There is definitely some trend here", 2, "There is definitely some trend here"},
}

func TestFlagParser(t *testing.T) {
	for _, tt := range logTests {
		res := ExtractColumn(tt.log, tt.column)
		if res != tt.out {
			t.Errorf("ExtractColumn(%q, %d) => %q, want %q", tt.log, tt.column, res, tt.out)
		}
	}
}
