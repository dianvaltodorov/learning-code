import Data.List

-- Task 1
member x [] = False
member x (y:ys) = x == y || (member x ys)

findColumns mat = let
  columns = transpose mat
  containsColumnInRow column row = and $ map (\x -> member x row) column
  containsColumnInAllRows column mat = or $ map (\row -> containsColumnInRow column row) mat
  in length (filter (\b -> b) (map (\column -> containsColumnInAllRows column mat) columns))


-- Task 3
type Plant = (String, Int, Int)
plantName (name, _, _) = name
plantMinTemp (_, minT, _) = minT
plantMaxTemp (_, _, maxT) = maxT
