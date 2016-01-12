(++) :: [a] -> [a] -> [a]
[]  ++    l2 = l2
(x:xs) ++ l2 = x:xs ++ l2

(!!) :: [a] -> Int -> a
(x:_) !! 0 = x
(_:xs) !! n = xs !! (n - 1)

elem :: a -> [a] -> Bool
elem _ [] = False
elem x (x:_) False

ask about case

pythagorian n = [(x, y, z) | x <- [1..n], y <- [1..(x - 1)], z <- [(max x y)..z], x^2 + y^2 == z^2]

poe' _ 0 = 1
pow' x n = x * pow' x (n - 1)

ета еквивалентност
