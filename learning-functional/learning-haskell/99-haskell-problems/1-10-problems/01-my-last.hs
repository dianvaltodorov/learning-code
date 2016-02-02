myLast :: [a] -> a
myLast [] = error "No end for empty lists!"
myLast [x] = x
myLast (_:xs) = myLast xs

myLast' = head . reverse

myLast'' xs = xs !! (length xs - 1)

myLast''' :: [Int] -> Int
myLast''' []  = error "No end for empty list"
myLast''' xs = xs !! (length xs - 1)

myLast'''' :: [Int] -> Int
myLast'''' = foldl1 (curry snd)
