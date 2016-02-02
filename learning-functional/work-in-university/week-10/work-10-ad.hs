-- Task 1
square x = x * x

-- Task 2
inc x = x + 1
dec x = x - 1

-- Task 3
even' = (mod x 2) == 0
odd' = (not even')

-- Tasj 4
between x a b = x > a && x < b

-- Task 5
pyth a b c = a^2 + b^2 == c^2

-- Task 6
lucky x = if even x
  then "You have guessed correctly!"
  else "Sorry! Try again next time!"

factorial n = if n == 1
  then 1
  else n * factorial n - 1
