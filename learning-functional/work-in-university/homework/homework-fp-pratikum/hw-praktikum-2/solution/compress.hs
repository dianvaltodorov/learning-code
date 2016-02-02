compress :: Eq a => [a] -> [a]
compress xs = let
  helper xs previousElement
    | null xs = []
    | previousElement == (head xs) = helper (tail xs) previousElement
    | otherwise = (head xs) : (helper (tail xs) (head xs))
  in (if (not (null xs)) then ((head xs) : helper xs (head xs)) else [])
