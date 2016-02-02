import Data.List

-- Task 1
multiSetUnion [] [] = []
multiSetUnion [] ys = ys
multiSetUnion xs [] = xs
multiSetUnion xs ys
  | (head xs) < (head ys) =  (head xs) : multiSetUnion (tail xs) ys
  | (head xs) > (head ys) = (head ys) : multiSetUnion xs (tail ys)
  | (head xs) == (head ys) = (replicate (max a b) (head xs)) ++ (multiSetUnion newXs newYs)
  where a = length (takeWhile (== (head xs)) xs)
        b = length (takeWhile (== (head ys)) ys)
        newXs = dropWhile (== (head xs)) xs
        newYs = dropWhile (== (head ys)) ys

multiSetIntersect [] [] = []
multiSetIntersect [] ys = []
multiSetIntersect xs [] = []
multiSetIntersect xs ys
  | (head xs) < (head ys) =  multiSetIntersect (tail xs) ys
  | (head xs) > (head ys) =  multiSetIntersect xs (tail ys)
  | (head xs) == (head ys) = (replicate (min a b) (head xs)) ++ (multiSetIntersect newXs newYs)
  where a = length (takeWhile (== (head xs)) xs)
        b = length (takeWhile (== (head ys)) ys)
        newXs = dropWhile (== (head xs)) xs
        newYs = dropWhile (== (head ys)) ys

multiSetSum [] [] = []
multiSetSum [] ys = ys
multiSetSum xs [] = xs
multiSetSum xs ys
  | (head xs) < (head ys) = (head xs) : multiSetSum (tail xs) ys
  | (head xs) > (head ys) =  multiSetSum xs (tail ys)
  | (head xs) == (head ys) = (replicate (a + b) (head xs)) ++ (multiSetSum newXs newYs)
  where a = length (takeWhile (== (head xs)) xs)
        b = length (takeWhile (== (head ys)) ys)
        newXs = dropWhile (== (head xs)) xs
        newYs = dropWhile (== (head ys)) ys

ss = ["moo", "bee", "eve", "abracadabra", "abcdefg", "mama", "z"]
mostCommonLetter s = let
    histogram xs = zip (nub xs) (map (\x -> length $ filter (==x) xs) (nub xs))
    decideOnLetter x y
      | (snd x) > (snd y) = x
      | (snd x) < (snd y) = y
      | otherwise = if (fst x) > (fst y) then x else y
    in (s , (foldr1 decideOnLetter  (histogram s)))


maxElement lst = foldr1 (\x y -> if (snd (snd x)) > (snd (snd y)) then x else y) (map mostCommonLetter ss)

removeElement lst x = takeWhile (\item -> (fst (snd x)) /= (fst (snd item)))

companies = [("Acme", 2.56), ("Buy'n'Large" , 12.5), ("Acme", 42), ("Smiths", 9.8) , ("Buy'n'Large" , 13.37), ("Acme", 10.4), ("Smiths", 10.6)]

type Quote = (String , Double)
bestCompany companies = let
  groupByCompany companies = map (\companyName -> filter (\c -> (fst c) == companyName) companies) (nub (map fst companies))
  meanCompanyQuotes quotesForCompany = (sum $ map snd quotesForCompany) / (fromIntegral  (length quotesForCompany))
  companyQuotesWithMaxMean = foldr1 (\x y -> if (meanCompanyQuotes x) > (meanCompanyQuotes y) then x else y) $ groupByCompany companies
  in ((fst (head companyQuotesWithMaxMean)), (minimum $ map snd companyQuotesWithMaxMean) , (maximum $ map snd companyQuotesWithMaxMean))
