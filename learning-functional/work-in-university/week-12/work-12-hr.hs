-- define a function which returns a
a = 5

-- функция, която увеличава със едно
inc x = x + 1

-- Curry - uses an already defined function but fixes one its arument
-- подавайки по малко аргументи на функцията не връща грешка, а същата функция с по-малко аргументи
add x y = x + y

addTwo x = x + 2

addFour = add 4

-- The maximum of two numbers
max' a b = if a > b then a else b

max'' a b
  | a > b = a
  | otherwise = b

-- Factorial
fact n = if n == 1
  then 1
  else n * fact (n - 1)

fact' 1 = 1
fact' n = n * fact' (n - 1)

fact'' n
  | n == 0  = 1
  | otherwise = n * fact'' (n - 1)

-- Count the digits of the number n
countDigits n
  | n < 10 = 1
  | otherwise = 1 + countDigits (div n 10)

countDigits' n = if  n < 10
  then 1
  else 1 + countDigits' (div n 10)

-- Reverse the digits of a nubmer
-- reverseDigits :: (Integral a) => a -> a -> a
reverseDigits n = reverseDigitsHelper n 0

reverseDigitsHelper n res
  | n == 0 = res
  | otherwise = reverseDigitsHelper (div n 10) (res * 10 + (mod n 10))

reverseDigits' n = let
  helper n res
    | n == 0 = res
    | otherwise = reverseDigitsHelper (div n 10) (res * 10 + (mod n 10))
  in helper n 0

-- Is a number pirme
prime n = let
  helper n i
    | i > (div n 2) = True
    | (mod n i) == 0 = False
    | otherwise =  helper n (i + 1)
  in  helper n 2

prime' 1 = False
prime' n = helper (n - 1)
  where
    helper 1 = True
    helper i = mod n i /= 0 && helper (i - 1)

fib n
 | n == 0 = 0
 | n == 1 = 1
 | otherwise = fib (n - 1) + fib(n - 2)

fib' 0 = 1
fib' 1 = 1
fib' n = fib' (n - 1) + fib' (n - 2)

fastpow x n
 | n == 0 = 1
 | even n = (fastpow x (div n 2))^2
 | otherwise = x * fastpow x (n - 1)
