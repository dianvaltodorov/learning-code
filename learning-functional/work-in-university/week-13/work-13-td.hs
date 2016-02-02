-- Fruit - нов тип
-- Apple | Banana | Cherry | Pineapple | Pear може да им се подава аргумент
-- можем да pattern match-ваме по тях
data Fruit = Apple | Banana | Cherry | Pineapple | Pear | Lemon deriving (Show, Eq)

isCitrus :: Fruit -> Bool
isCitrus Lemon = True
isCitrus _ = False

yolo :: Int -> Int
yolo x y = fasd
-- долните са еквиваленти
-- Lemon :: Fruit
-- 5     :: Char
-- 'a'   :: Char
-- "asd" :: [Char]
-- data  Bool = False | True

-- Главните букви също за важни. Това е изискване към класове

fruits :: [Fruit]
fruits = [Apple, Pear, Lemon]

-- data Maybe a = Nothing | Just
--  дефинирано е така. Типът не е Maybe, а е Maybe a
-- :t Nothing :: Maybe a
-- няма полиморфичен смисъл

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday deriving (Show, Eq, Ord, Bounded, Enum)
-- minBound :: Day -> Monday
-- maxBound :: Day -> Sunday
-- succ Monday
-- pred Monday


data FailableDouble =  Failure | OK Double deriving Show

-- safeDivide :: (Double a) => a -> a -> FailableDouble
safeDivide a b = if b == 0 then Failure else (OK (a/b))

-- safeDivide' :: (Double a) => a -> a -> FailableDouble

safeDivide' _ 0 = Failure
safeDivide' a b = OK(a/b)

data Person = Person String Int Fruit deriving Show

getAge :: Person -> Int
getAge (Person _ a _ ) = a

getName :: Person -> [Char]
getName (Person name _ _) = name

getFavouriteFruit :: Person -> Fruit
getFavouriteFruit (Person _ _ f) = f

data Car = Car {
                maufacturer :: String,
                model :: String,
                year :: Int }
                deriving (Show)

car1 :: Car
car1 = Car "Lada" "Niva" 1999

car2 :: Car
car2 = Car "Lada" "48"  1980


-- data List = Empty | Cons a (List a)
-- [5] захар за 5 : []
-- ['a', 'b'] захар за 'a' : ('b' : [])

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show)

tree :: Tree Int
tree = Node 10
            (Node 7
                  (Node 5
                        (Node 3 EmptyTree EmptyTree)
                        EmptyTree)
                  (Node 9 EmptyTree EmptyTree))
            (Node 17
                  (Node 13 EmptyTree
                           (Node 15 EmptyTree EmptyTree))
                  (Node 20
                          (Node 18 EmptyTree EmptyTree)
                          (Node 18 EmptyTree EmptyTree)))

heightTree :: Tree a -> Int
heightTree EmptyTree = 0
heightTree (Node x left right) = 1 + max (heightTree left)  (heightTree right)


inOrder :: Tree a -> [a]
inOrder EmptyTree = []
inOrder (Node x left right) =  inOrder left ++ [x] ++ inOrder right

treeElem :: (Ord a) => a -> Tree a -> Bool
treeElem _ EmptyTree = False
treeElem el (Node x l r)
  | el == x = True
  | el < x = treeElem el l
  | otherwise = treeElem el r


insertElementIntoTree :: (Ord a) => a -> Tree a -> Tree a
insertElementIntoTree el EmptyTree = Node el EmptyTree EmptyTree
insertElementIntoTree el (Node x l r)
  | el == x = Node x l r
  | el < x  = Node x (insertElementIntoTree el l) r
  | otherwise = Node x l (insertElementIntoTree el r)

tree2 :: Tree Int
tree2 = foldr insertElementIntoTree EmptyTree [1,2,3,12,3,1,3,123,12,12,3,5,67,7,4,43,23,3,4,234,34,0]

tree
