#lang racket

(load "gcd.rkt")

(define (scd x y)
  (/ (* x y) (gcd x y)))
