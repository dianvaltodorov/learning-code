#lang racket

(define (gcd x y)
  (define (helper a b)
    (cond ((= a b) a)
          ((> a b) (helper (- a b) b))
          ((< a b) (helper a (- b a)))))
  (helper x y))
