-- Задача 1. Да се напише фунцкия на Haskell, която по подадено естествено число
-- намира факторизацията му на прости делители.
-- > primeFactors 315
-- [3, 3, 5, 7]
-- > primeFactors 1023
-- [3, 11, 31]


primes = filter isPrime [1..]
isPrime x = let
  helper x i
    | i > (div x 2) = True
    | (mod x i) == 0 = False
    | otherwise = helper x (i + 1)
  in helper x 2

primeFactors :: Integral a => a -> [a]
primeFactors x = let
    helper x i
      | i > x = []
      | mod x i == 0 && (isPrime i) = i : (helper (div x i) i)
      | otherwise = helper x (i+1)
    in helper x 2

-- [] -> []
-- [1] -> [1]
-- [1, 1] -> [1]
-- [1, 1, 2] -> [1, 2]
-- Задача 2. Да се напише функция на Haskell, която премахва повтарящите се поредни елементи от списък. Редът на елементите в списъка остава непроменен.
-- > compress [1, 1, 2, 3, 2, 2, 2, 4]
-- [1,2,3,2,4]
-- > compress "aaaabccaadeeee"
-- "abcade"

compress :: Eq a => [a] -> [a]
compress xs = let
  helper xs previousElement
    | null xs = []
    | previousElement == (head xs) = helper (tail xs) previousElement
    | otherwise = (head xs) : (helper (tail xs) (head xs))
  in (if (not (null xs)) then ((head xs) : helper xs (head xs)) else [])


-- Задача 3. Да се напише фунцкия на Haskell, която проверява дали подаден списък е палиндром.
--
-- Забележка: Да се реализира чрез п(о)дходящо използване на fold!
--
-- > palindrome [1, 2, 3]
-- False
-- > palindrome "21abxsoba12"
-- True
palindrome :: Eq a => [a] -> Bool
palindrome xs = foldr (&&) True (zipWith (\x y -> x == y) xs (reverse xs))
