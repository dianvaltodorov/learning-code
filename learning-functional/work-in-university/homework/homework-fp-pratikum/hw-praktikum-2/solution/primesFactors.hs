primeFactors :: Integral a => a -> [a]
primeFactors x = let
    helper x i
      | i > x = []
      | mod x i == 0 && (isPrime i) = i : (helper (div x i) i)
      | otherwise = helper x (i+1)
    in helper x 2
