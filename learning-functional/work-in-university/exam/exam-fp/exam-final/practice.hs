approximate :: (Num a, Ord a) => (a -> a) -> [(a->a)] -> (a->a)
approximate f l = (\x -> (minF [(h, abs $ (h x) - (f - x)) | h <- l]) x)

minF :: (Num a, Ord a) => [((a -> a), a)] -> (a->a)
minF [] = error "yolo"
minF (p:ps) = helper (fst p) (snd p) ps
  where helper h minVal lst
    | null lst                =
    | snd (head lst) < minVal = helper (fst $ head lst) (snd $ head lst) (tail lst)
    | otherwise               = helper h minVal (tail lst)

iterator :: (Num)
iterator = all (map (\x -> 1 + (fst  x) == snd x) $ zip l (tail l))

type Battery = (Int, Double)
bestBarttery :: [Battery] -> Int -> Double
bestBarttery batteries k = foldr1 (\x y -> if (fst x) < (fst y) then x else y)  (filter (\battery -> fst battery > k) batteries)


listToFunction lst = (\x -> if presentInList x lst then x + 10 else 0)
  where presentInList x []     = False
        presentInList x (y:ys) = x == y || (presentInList x ys)




listToPredicate lst = (\x y -> pairPresentIn (x, y) lst)
 where pairPresentIn x [] = False
       pairPresentIn x (p:pairs) = (fst x == fst p) && (snd x == snd p) || (pairPresentIn x pairs)

type Waffle = (Int, Double)
healthiestWaffle :: [Waffle] -> Double -> Int
healthiestWaffle waffles s = foldr1 (\x y -> if (fst x) < (fst y) then x else y)  (filter (\waffle -> snd waffle < s) waffles)
