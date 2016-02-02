-- Зад.1. Да се напише функция primeSqSum, която намира сумата на квадратите на
 -- всички прости числа в даден интервал:
-- primeSqSum 1 10 -> 87      -- 87 = 22 + 32 + 52 + 72
-- primeSqSum 10 20 -> 940    -- 940 = 112 + 132 + 172 + 192
-- primeSqSum 24 28 -> 0
-- Is a number pirme

isPrime :: Int-> Bool
isPrime n = let
  helper n i
    | n == 1 = False
    | i > (div n 2) = True
    | (mod n i) == 0 = False
    | otherwise =  helper n (i + 1)
  in  helper n 2

primeSqSum :: Int -> Int -> Int
primeSqSum a b = sum (map (^2) [x | x<-[a..b], isPrime x])

-- - Зад.2. Да се напише функция seriesSum, която намира сумата на първите n члена на редицата 1, -1/2, 1/3, -1/4, ...:
-- seriesSum 3 -> 0.8333...   -- 0.8333... = 5/6 = 1 - 1/2 + 1/3
seriesSum n = let
  helper i
    | i > n = 0
    | otherwise = 1/ (fromIntegral denominator) + (helper (i + 1))
    where
      denominator =  i * ((-1) ^ i)
  in helper 1

-- Зад.3. Да се напише функция slice, която взима подсписъка от i-тия до j-тия елемент на даден списък (броейки от 1):
-- slice 3 7 "abcdefghi" -> "cdefg"
-- slice 2 5 [1..] -> [2,3,4,5]

slice i j xs = map (\idx -> xs !! idx) [(i-1)..(j-1)]

--
-- Зад.4. Да се напише функция removeNth, която премахва всеки n-ти елемент от даден списък:
-- removeNth 3 [1..10] -> [1,2,4,5,7,8,10]
--
removeNth i xs =  take (i - 1) xs ++ drop i xs
-- Зад.5. Да се напише функцията merge, която слива два сортирани списъка в нов, също сортиран списък:
-- merge [1,4,8,9] [2,3,5,6,7,10] -> [1,2,3,4,5,6,7,8,9,10]
-- Заб.: реализирайте класическия алгоритъм за сливане на списъци - решения от типа "merge l1 l2 = sort (l1 ++ l2)" няма да се зачитат!

merge [] [] = []
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x < y then x : (merge xs (y:ys)) else y: (merge (x:xs) ys)

-- Бонус1: Да се напише функция mergeSort, която сортира списък по едноименния алгоритъм.

mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort (take (div (length xs) 2) xs))  (mergeSort (drop (div (length xs) 2) xs))
-- Бонус2: Твърдението на Голдбах (Christian Goldbach) гласи, че всяко четно
-- число (освен 2) може да се представи като сбор на две прости числа по поне
-- един начин. Това твърдение е проверено за всички числа до 4х1018 и за целите
-- на това домашно ще го считаме за вярно. Да се напише функция goldbachPair,
-- която връща едно разбиване на четно число на две прости събираеми във вида
-- на наредена двойка:

-- goldbachPair 8 -> (3,5)
-- goldbachPair 10 -> (3,7)   -- а може и (5,5)

goldbachPair n = head [(x,y) | y <- [2..n] , x <- [2..y], (isPrime x) && (isPrime y), x + y == n]
