#lang racket
(define (sum-of-two-largest a b c)
  (cond ((>= a b c) (* a b))
        ((>= a c b) (* a c))
        ((>= b a c) (* a b))
        ((>= b c a) (* b c))
        ((>= c a b) (* c a))
        ((>= c b a) (* c b))))

(sum-of-two-largest 1 2 4)
(sum-of-two-largest 2 3 4)
(sum-of-two-largest 9 3 4)
(sum-of-two-largest 1 2 4)