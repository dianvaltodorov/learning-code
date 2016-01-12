saySign x
  | x > 0 = "Positive"
  | x == 0 = "Zero"
  | x < 0 = 	"Negative"

-- [1, 2, 3]
-- 1 : [2, 3]
-- [2, 3] ++ [1]
-- "HELLO" ++ "World"
-- [1, 2] ++ "iei"
-- []

-- null [1, 2, 3]
-- let x =  [1, 2, 3, 4, 5, 6]
-- head x
-- tail x
-- init x
-- last x
-- x !! 0
-- x !! 10
-- take x 3
-- drop x 4
-- reverse x
-- elem 3 x

-- Task 1
replicate' n x  = if n == 0
  then []
  else x : replicate' (n - 1) x

replicate'' n x  = if n == 0
    then []
    else [x] ++ replicate' (n - 1) x

-- Task 2
take' n xs = if n == 0 || null xs
  then []
  else (head xs) : take' (n - 1) (tail xs)

take'' _ [] = []
take'' n xs @ (h : t)
  | n == 0 = []
  | otherwise = h : take'' (n - 1) t

-- Pattern matching with one element

-- f (x : [])  -- точно един
-- f (x : _)  -- поне един
-- f (x : y : []) -- точно два
-- f (x : y : _) -- поне два

-- Task 3
isPrime x = let
  helper x i
    | i > (div x 2) = True
    | (mod x i) == 0 = False
    | otherwise = helper x (i + 1)
  in helper x 2

isPrime' x =
  helper x 2
  where
    helper x i
      | i > (div x 2) = True
      | (mod x i) == 0 = False
      | otherwise = helper x (i + 1)

divisors n = [ d | d  <- [1..n], (mod n d) == 0]

isPrime''  1 = False
isPrime''  n = null [ d | d  <- [2..(floor (sqrt (fromIntegral n)))], (mod n d) == 0]


isPrime'''  1 = False
isPrime'''  n = null [ d | d  <- [2..sqn], (mod n d) == 0]
  where sqn = (floor (sqrt (fromIntegral n)))

isPrime''''  1 = False
isPrime''''  n = let
  sqn = (floor (sqrt (fromIntegral n)))
  in null [ d | d  <- [2..sqn], (mod n d) == 0]

-- Task 4
primes = [ x | x <- [1..], isPrime x]
primes' = filter isPrime [1..]

-- Task 5
nthPrime n = primes !! (n - 1)

-- Task 6
first (x, _, _)  = x
second (_, x, _)  = x
third (_, _, x)  = x

-- let x =


-- Task 7
descartes xs ys =  [(x, y) | x <- xs, y <- ys]
evens = [ 2 * x | x <- [1..]]

-- Task 8
pitagorians = [(x,y,z) | x <- [1..100], y <- [1..100], z <- [1..100], x + y + z  <= 100, x^2 + y^2 == z ^2]

fib n
 | n == 1 = 0
 | n == 2 = 1
 | otherwise = fib (n - 1) + fib(n - 2)

let curr = [1,2,1] in zipWith (+) (0:curr) (curr++[0])
triag n = helper 1 [1]
  where helper k l
    | n == k = []
    | otherwise zipWith (+) (0:curr) (curr++[0])
