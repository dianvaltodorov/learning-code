import Data.Char

countDigits :: Int -> Int
countDigits n
  | abs n < 10 = 1
  | otherwise = 1 + countDigits (div (abs n) 10)

reverseDigits :: Int -> Int
reverseDigits n = reverseHelper 0 n

reverseHelper :: Int-> Int -> Int
reverseHelper result n
  | n == 0 = result
  | otherwise = reverseHelper (result * 10 + (mod n 10)) (div n 10)

reverseDigits' :: Int -> Int
reverseDigits' = helper 0 where
  helper res n
    | n == 0 = res
    | otherwise = helper (res * 10 + (mod n 10)) (div n 10)

isPrime :: Int -> Bool
isPrime 1 = False
isPrime x = helper 2 x where
  helper i n
    | i >= n = True
    | (mod n i) == 0 = False
    | otherwise = helper (i + 1) n

isPrime' :: Int -> Bool
isPrime' 1 = False
isPrime' x = let
  helper divisor x
    | divisor == 1 = True
    | mod x divisor == 0 = False
    | otherwise = helper (divisor - 1) x
  in helper (x - 1) x

listDigits :: Int -> [Int]
listDigits = helper [] where
  helper res n
    | n == 0 = res
    | otherwise = helper ((mod n 10) : res) (div n 10)

listDigits' :: Int -> [Int]
listDigits' x
  | x < 10 = [x]
  | otherwise = listDigits' (div x 10) ++ [(mod x 10)]

removeNonUppercase :: [Char] -> [Char]
removeNonUppercase xs = [x | x <- xs,  x `elem` ['A'..'Z']]

removeNonUppercase' str = filter isUpper str

elem' :: (Eq a) =>  a -> [a] -> Bool
elem' _ [] = False
elem' x (y : ys)
  | x == y = True
  | otherwise = elem' x ys

elem'' :: (Eq a) =>  a -> [a] -> Bool
elem'' _ [] = False
elem'' x l
  | x == (head l) = True
  | otherwise = elem'' x (tail l)

addHead l@(x:_) = x:l ++ [x]

elem''' x =  foldl (\ isElem ac -> if x == y
                                  then True
                                  else isElem)

foldl' ::  (a -> b -> a) -> a -> [b] -> a
foldl'  op init l
  | null l = init
  | otherwise = foldl op (op init (head l)) (tail l)
