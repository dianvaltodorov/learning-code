myLength :: [a] -> Int
myLength xs = sum([1 | _ <- xs])

myLength' :: [a] -> Int
myLength' xs = sum([1 | _ <- xs])

myLength'' :: [a] -> Int
myLength'' xs = myLengthHelper xs 0
  where
    myLengthHelper [] n = n
    myLengthHelper (_:xs) n = myLengthHelper xs (n+1)
