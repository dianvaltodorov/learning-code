import Data.List

fst' (x, y) = x
snd' (x, y) = y

repeat' x = x : repeat' x

ones :: [Integer]
ones = 1 : ones

naturals :: [Integer]
naturals = helper 1 where
  helper x = x : helper (x + 1)

points :: Floating a => a -> a -> [(a,a)]
points x y = (x, y) : points (x + 1) (y + 1)

filterPoints :: Eq a => [(a, a)] -> [(a, a)]
filterPoints points = filter (\point -> (fst point) == (snd point)) points

distance :: Floating a => [(a, a)] -> [a]
distance points = map (\point -> sqrt ((fst point)^2 + (snd point)^2)) points

tribonacci :: [Integer]
tribonacci = map helper [1..]
  where helper 0 = 1
        helper 1 = 1
        helper 2 = 2
        helper n = helper (n - 1) + helper(n - 2) + helper(n - 3)

tribonacci' :: [Integer]
tribonacci' = helper 1 1 1
  where helper current prev1 prev2 = current : helper (current + prev1 + prev2) current  prev1

sieve = helper [2..] where
  helper (prime:rest) = prime : (helper (filter (\x-> (mod x prime) >= 0) rest))

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
  let smallerSorted = quicksort [a | a <- xs, a <= x]
      biggerSorted = quicksort [a | a <- xs, a > x]
  in  smallerSorted ++ [x] ++ biggerSorted

selSort :: (Ord a) => [a] -> [a]
selSort [] = []
selSort xs = minimum xs : (selSort (delete (minimum xs) xs))
