import Data.List
import Data.Char
import System.Environment

type Board = [[Int]]
type Row = [Int]
type Column = [Int]
type Block = [Int]
type Cell = (Int, Int)

-- main :: IO ()
-- main = do
--   writeBoardToFile board3
--   args <- getArgs
--   if null args
--      then chooseOption
--      else if length args == 1
--             then readBoardFromFile (args !! 0)
--             else wrongInput

chooseOption :: IO()
chooseOption = do
  putStrLn "Choose option:\n1) generate a sudoku board\n2) enter a sudoku board for me solve a sudoku board\n3) exit"
  choice <- getChar
  makeDecision choice
    where makeDecision x
            | x == '1' = putStrLn "Generating board"
            | x == '2' = readBoardFromUserInput
            | x == '3' = return ()
            | otherwise = chooseOption

playAgain :: IO()
playAgain = do
  putStrLn "Play Again(Y/N):"
  choice <- getChar
  makeDecision choice
    where makeDecision x
            | x == 'Y' || x == 'y' = chooseOption
            | x == 'N' || x == 'n' = return()
            | otherwise = playAgain

readBoardFromUserInput :: IO()
readBoardFromUserInput = do
  input <- sequence (replicate 10 getLine)
  let board = parseBoardFromUserInput input
  prettyPrintBoard board

readBoardFromFile :: String -> IO()
readBoardFromFile filename =  do
    contents <- readFile filename
    let board = parseBoardFromFile contents
    prettyPrintBoard board

writeBoardToFile :: Board -> IO ()
writeBoardToFile board = do
  writeFile "YOLO.txt" (boardToString board)

wrongInput :: IO ()
wrongInput =  putStrLn "Wrong Inputt"

parseBoardFromUserInput :: [String] -> Board
parseBoardFromUserInput ls =  tail (map (map (\c -> if isDigit c then digitToInt c else 0)) ls)

parseBoardFromFile :: String -> Board
parseBoardFromFile s =  map (map (\c -> if isDigit c then digitToInt c else 0)) (words s)

printBoard :: Board -> IO ()
printBoard board = print board

prettyPrintBoard :: Board -> IO ()
prettyPrintBoard board = putStrLn $ boardToPrettyString board


rowToPettyString :: Row -> String
rowToPettyString []      = "|"
rowToPettyString (0:xs)  = "|   " ++ rowToPettyString xs
rowToPettyString (x:xs)  = "| " ++ [intToDigit x] ++ " " ++ rowToPettyString xs

boardToPrettyString :: Board -> String
boardToPrettyString board = foldr1 (\x y -> x ++ "\n" ++ y)  (intersperse (replicate 37 '-') (map rowToPettyString board))

boardToString :: Board -> String
boardToString board = concat (intersperse "\n" (map (\row -> map (\x -> if elem x [1..9] then intToDigit x else '.') row)  board))

-- =========================== Example Data ==============================
board1 :: Board
board1 = [[0, 0, 7, 6, 0, 4, 3, 0, 1],[2, 4, 6, 0, 0, 3, 9, 0, 5],[3, 5, 1, 9, 0, 8, 7, 0, 0],[1, 2, 8, 5, 3, 0, 6, 9, 4],[6, 3, 4, 8, 0, 2, 0, 5, 7],[7, 9, 5, 4, 6, 1, 8, 3, 2],[5, 1, 9, 2, 8, 6, 4, 7, 3],[4, 7, 2, 3, 1, 9, 5, 6, 8], (replicate 9 0)]]

board2 :: Board
board2 =[[1,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,7,3],[0,0,2,0,1,0,0,0,0],[0,0,0,0,4,0,0,0,9]]

board3 :: Board
board3 = [[0,2,0,0,1,4,0,0,0],[0,1,9,0,2,0,0,0,0],[0,3,0,5,0,9,0,0,0],[0,9,0,0,0,0,0,1,7],[3,0,0,2,0,1,0,0,9],[7,8,0,0,0,0,0,4,0],[0,0,0,9,0,3,0,7,0],[0,0,0,0,6,0,4,9,0],[0,0,0,8,5,0,0,2,0]]

board4 :: Board
board4 = [[8,2,7,1,5,4,3,9,6],[9,6,5,3,2,7,1,4,8],[3,4,1,6,8,9,7,5,2],[5,9,3,4,6,8,2,7,1],[4,7,2,5,1,3,6,8,9],[6,1,8,9,7,2,4,3,5],[7,8,6,2,3,5,9,1,4],[1,5,4,7,9,6,8,2,3],[2,3,9,8,4,1,5,6,7]]

-- ======================== Pure functions =================
boardSize :: Int
boardSize = 9

getColumns :: Board -> [Column]
getColumns = transpose

getColumn :: Int -> Board -> Column
getColumn i board = map (!! i) board

getRows :: Board -> [Row]
getRows board = board

getRow ::Int -> Board -> Row
getRow i board = board !! i

-- getBlocks :: Board -> [Block]
-- getBlocks board = let
--   indexes = [0, 3, 6]
--   chunks = map (\chunk-> take 3 $ drop chunk board) indexes
--   deconstructed =  map transpose (map (\chunk -> (map (\row -> map (\x -> take 3 $ drop x row) indexes) chunk))  chunks)
--   in  foldl (++) [] (map (map concat) deconstructed)

getBlocks :: Board -> [Block]
getBlocks board = let
  indexes = [0, 3, 6]
  chunks = map (\chunk-> take 3 $ drop chunk board) indexes
  triples row = map (\x -> take 3 $ drop x row) indexes
  trppleBlocks = (map (\chunk -> (map triples chunk))  chunks)
  deconstructed =  map transpose trppleBlocks
  in  foldl (++) [] (map (map concat) deconstructed)


getAllBlanks :: Board -> [Cell]
getAllBlanks board = [ (y,x) | y <- [0..8], x <- [0..8], (getCellContent (y,x) board) == 0]

allCoordinates :: [Cell]
allCoordinates = [(x, y)| x<-[0..8], y<-[0..8]]

blank :: Board -> Cell
blank = head . getAllBlanks

getBlockForCell :: Cell -> Board -> Block
getBlockForCell (i, j) board = (getBlocks board) !! ((div i 3) + (div j 3))

getCellContent ::  Cell -> Board -> Int
getCellContent (i, j) board = (board !! i ) !! j

getTakenValues :: Cell -> Board-> [Int]
getTakenValues (i, j) board = (getRow i board) ++ (getColumn j board) ++ (getBlockForCell (i, j) board)

getAllowedCellValues :: Cell -> Board -> [Int]
getAllowedCellValues (i, j) board = [0..9] \\ (nub (getTakenValues (i,j) board))

containsAllNumbersInRange1 ::(Integral a) => a -> [a] -> Bool
containsAllNumbersInRange1 n xs = containsAllNumbersInRange 1 n xs
  where  containsAllNumbersInRange a b xs = [a..b] == sort xs

isSolved :: Board -> Bool
isSolved board = checkRows board && checkColumns board && checkBlocks board
  where checkRows board = all (\xs -> containsAllNumbersInRange1 9  xs) (getRows board)
        checkColumns board = all (\xs -> containsAllNumbersInRange1 9 xs) (getColumns board)
        checkBlocks board = all (\xs -> containsAllNumbersInRange1 9 xs) (getBlocks board)

validateBoardDimensions :: Board -> Bool
validateBoardDimensions board = (length board == 9) && all (\row -> (length row == 9)) board

validateBoardContent :: Board -> Bool
validateBoardContent board =  all (\row -> all (\x -> elem x [0..9]) row) board

isInputBoardValid :: Board -> Bool
isInputBoardValid board = validateBoardContent board && validateBoardDimensions board

hasViolations :: Board -> Bool
hasViolations board = hasDuplicates rows && hasDuplicates columns && hasDuplicates blocks
  where rows = map (\row -> filter (\x -> x /= 0) row) (getRows board)
        columns =  map (\col -> filter (\x -> x /= 0) col) (getColumns board)
        blocks =   map (\block -> filter (\x -> x /= 0) block) (getBlocks board)
        hasDuplicates xs =  not (all (\lst -> lst == nub lst) xs)

allBlankSudoku :: Board
allBlankSudoku = [[0 | _ <- [0..8]] | _ <- [0..8]]

updateCell :: Cell -> Int -> Board -> Board
updateCell (i, j) x board = newBoard
  where row      = getRow i board
        newRow   = (take j row) ++ [x] ++ (drop (j + 1) row)
        newBoard = (take i board) ++ [newRow] ++ (drop (i + 1) board)


solve :: Board -> Maybe Board
solve board
  | hasViolations board = Nothing  -- There's a violation in s
  | isSolved board  = Just board   -- board is already solved
  | otherwise = pickASolution $ possibleSolutions board

updatedBoards :: Board -> [Board]
updatedBoards board = map (\x -> updateCell (blank board) x board) (getAllowedCellValues (blank board) board)

possibleSolutions :: Board -> [Maybe Board]
possibleSolutions board =
  map solve (updatedBoards board)

pickASolution :: [Maybe Board] -> Maybe Board
pickASolution []   = Nothing
pickASolution suds = head suds
