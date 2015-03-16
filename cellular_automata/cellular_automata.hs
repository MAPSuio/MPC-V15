
-- Correct (read "general") implementation that handles infinite sequences
-- using the Pointer comonad.

import Control.Comonad

data Pointer a = P [a] a [a] deriving (Eq, Show)

instance Functor Pointer where
  fmap f (P as a as') = P (fmap f as) (f a) (fmap f as')
                        
moveLeft :: Pointer a -> Pointer a
moveLeft (P (y:ys) a xs) = P ys y (a:xs)
moveLeft _ = error "Cannot move left."

moveRight :: Pointer a -> Pointer a
moveRight (P ys a (x:xs)) = P (a:ys) x xs
moveRight _ = error "Cannot move right."

pointAllLeft :: Pointer a -> [Pointer a]
pointAllLeft p = tail $ iterate moveLeft p
  
pointAllRight :: Pointer a -> [Pointer a]
pointAllRight p = tail $ iterate moveRight p
  
instance Comonad Pointer where
  extract (P _ a _) = a
  duplicate p = P (pointAllLeft p) p (pointAllRight p)
            
------------------------------------------------------------------------------            

rule :: Pointer Bool -> Bool
rule (P (y:ys) a (x:xs)) = if a then not (x && y)
                           else x || y
                                                
pop :: Pointer Bool
pop = P (repeat False) True (repeat False)

applyRule :: Pointer Bool -> Int -> Pointer Bool
applyRule p n = if n == 0 then p
                else applyRule (p =>> rule) (n-1)

countTrue :: Pointer Bool -> Int -> Int
countTrue (P xs a ys) n = (length $ filter id (take n xs)) + (if a then 1 else 0) + (length $ filter id (take n ys))

main :: IO ()
main = print $ countTrue (applyRule pop 253) 253


--------------Functions for printing fractal---------------------------------
--(Not part of solution)

displayState :: Pointer Bool -> Int -> [Char]
displayState (P ys a xs) n = fmap (\x -> if x then 'x' else ' ') ((reverse $ take n ys) ++ [a] ++ (take n xs))

h :: Pointer Bool -> Int -> Int -> IO ()
h p n it = do print $ displayState p n
              if it == 0 then return ()
                else 
                do
                  let p' = p =>> rule
                  h p' n (it-1)

