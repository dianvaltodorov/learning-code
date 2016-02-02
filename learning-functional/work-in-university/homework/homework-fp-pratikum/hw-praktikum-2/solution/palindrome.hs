palindrome :: Eq a => [a] -> Bool
palindrome xs = foldr (&&) True (zipWith (\x y -> x == y) xs (reverse xs))
