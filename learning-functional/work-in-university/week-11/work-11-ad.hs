saySign x
 | x > 0 = "Positive"
 | x == 0 = "Zero"
 | x < 0 = 	"Negative"

uselses a b c d
 | a == 0 || b == 0 || c == 0 || d == 0 = 1
 | otherwise = a + b + c + d

factorial 0 = 1
factorial n = n * factorial(n - 1)

fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (m - 1) + fibonacci ( n - 2)

countRoots a b c =
  | 
  |
