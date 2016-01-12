-- $:: a - > b
-- f $ x = f xDido is da man <3
-- filter even [1..10]
-- map sq (filter even [1..10])
-- map sq $ filter even [1..10]
-- sqrt 1 + 3 + 5 vs. sqrt $ 1 + 3 + 5 vs. sqrt (1 + 3 + 5)

-- :t - типа на сиситемата
-- :i - типа, къде е дефинирано, приротет и асоциативност

--Task 1
task1 = sum $ map (*2) $ filter odd [1..10]
sum' = foldl (+) 0

-- Function Composition
-- f . g x = \x -? f (g x)
-- let xs = [1, 2, 7, 8, -3, 6,-9, 5, 0]

negate' x = x * (-1)

-- (negate.abs) 4 -> прилагането на функцията е с най-голям приоритет

fg = negate.abs

-- Task 2
task2  = reverse . take 3 $ filter even [1..]
task2' = reverse $ take 3 $ filter even [1..]
task2''  = reverse . take 3 . filter even $ [1..]
task2''' = (reverse . take 3 .filter even)  [1..]


-- Task 3
zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x,y) : (zip' xs ys)

-- Task 4
zipWith' :: (a -> b -> c) -> [a] -> [b] ->[c]
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys
zipWith' _ _ _ = []

--  IMPORT modules

-- import Data.Char
-- toLower 'A' -> 'a'
-- toUpper 'b' -> 'B'

-- import Data.List
-- interSperse
-- and $ map (>0) [-1, 0, 1, 2]
-- intersperse 0 [1,2,3,4,5,6]
-- and $ map (>0) [-1, 0, 1, 2]
-- any (>5) map (>0) [-1..2]
-- all (>5) map (>0) [-1..2]
-- nub [1,2,3,4,3,2,1,2,3,4,3,2,1]
-- find (< 0) [1..5]
-- find (> 4) [1..5]

-- import Data.Map
-- import Data.Set

-- Conflict in importing modules
-- import Data.List
-- import Data.Char
-- there is a filter both of the modules

-- import qualified Data.List as L
-- import qualified Data.Set as S
-- L.filter
-- S.filter
