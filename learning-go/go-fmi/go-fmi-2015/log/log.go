package log

import (
	"regexp"
	"strings"
)

const (
	datePattern      = `(\d+\-\d+\-\d+\s\d+:\d+:\d+)`
	ipPattern        = `(\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b)`
	messagePattern   = `(.*)`
	logLinePattern   = datePattern + `\s` + ipPattern + `\s` + messagePattern
	newLineCharacter = "\n"
)

var logLineRegExp = regexp.MustCompile(logLinePattern)

// ExtractColumn returns the column for
func ExtractColumn(logContents string, column uint8) string {
	logContentsLines := strings.Split(logContents, "\n")

	for _, line := range logContentsLines {
		matches := logLineRegExp.FindStringSubmatch(line)t
		return matches[column+1]
	}

	return ""
}
