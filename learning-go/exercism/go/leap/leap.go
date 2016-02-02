package leap

const testVersion = 2

func IsLeapYear(y int) bool {
	return (y%400 == 0) || y%100 != 0 && y%4 == 0
}
