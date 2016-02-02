elementAt :: [a] -> Int -> a
elementAt list k = list !! (k - 1)

elementAt' :: [a] -> Int -> a
elementAt' (x:_) 1 = x
elementAt' [] _ = error "Index out of bounds"
elementAt' (x:xs) k
  | k < 0     = error "Index negative"
  | otherwise = elementAt xs (k - 1)
