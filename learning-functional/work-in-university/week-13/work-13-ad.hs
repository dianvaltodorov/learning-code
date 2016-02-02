-- test = True
--
-- floor (sqrt (fromIntegral 44))
--
-- floor (sqrt $ fromIntegral 44)
--
-- floor $ sqrt $ fromIntegral 4 -- прилагаме floor върху sqrt върху fromIntegral от 4
--
-- let f1 x = floor . sqrt . fromIntegral $ x -- композираме floor със sqrt със fromIntegral и получената функция прилагаме върху x
-- let f2 = (-)
-- let f3 = (-)
--
-- (^2) 3 -- 8
-- (2^) 3 -- 9 отрязване
--
-- map ($ 2) [ (4+), (succ), (6^)]
--
-- (^3) 3
--
-- map (succ . (^2)) [1..10]

--
-- Зад.1. Да се напише функцията sumProducts, която приема списък от списъци от
-- числа и връща сумата на всички произведения на числата в даден списък:
-- sumProducts [[1,2,3], [4,5], [], [-2,3,0,5,1]] -> 26 -- 26 = 6 + 20 + 0 + 0
sumProducts :: (Num a) => [[a]] -> a
sumProducts ls = sum $ map product ls

-- Зад.2. Да се напише функцията occurrences, която приема два списъка от числа и
 -- връща списък от броя срещания на елементите от първия списък във втория:
-- occurrences [1..6] [1,3,4,3,2,3,3,0,5,3,1] -> [2,1,3,1,1,0]

isSquare m = all( == (length m)) $ m
count x l = length [ k | k <- l, k == x]
count' x l = length $ filter ( == x) l
count'' x l = length (filter ( == x) l)

occurrences lst1 lst2 = map (\x -> count x lst2) lst1


-- Зад.3. Да се напише функцията mainDiag, която намира главния диагонал на квадратна матрица от числа:
-- mainDiag [[1,2,3],[4,5,6],[7,8,9]] -> [1,5,9]

mainDiag m = helper 0 m
  where helper i m
          | i == (length m) = []
          | otherwise =  ((m !! i) !! i) : helper (i + 1)  m

mainDiag' = zipWith (!!) [0..]
mainDiag'' m = map (\idx -> ((m !! idx) !! idx)) [0..(length(m) - 1)]
-- Зад.4. Да се напише функция isDiagonal, която проверява дали дадена матрица е квадратна:
-- isDiagonal [[1,2,3],[4,5,6],[7,8,9]] -> True
-- isDiagonal [[1..4],[5..8],[9..12]] -> False
--
-- Зад.5. Да се напише функцията sndDiag, която намира вторичния диагонал на квадратна матрица от числа:
-- sndDiag [[1,2,3],[4,5,6],[7,8,9]] -> [3,5,7]
--
-- Зад.6. Да се напише функцията matchLengths, която проверява дали всички списъци от списък със списъци са с еднаква дължина:
-- matchLengths [[1..4],[0..3],[5,4,8,10]] -> True
-- matchLengths [[1..4],[0..3],[],[5,4,8,10]] -> False
--
-- Зад.7. Да се напише функцията composeList, която връща безкраен списък от композициите на дадена едноаргументна функция f:
-- let functions = composeList succ in take 5 $ map ($1) $ functions -> [2,3,4,5,6]
