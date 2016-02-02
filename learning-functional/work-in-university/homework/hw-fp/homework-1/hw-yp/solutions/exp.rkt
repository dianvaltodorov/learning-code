#lang racket

(define (exp x n)
  (define (helper i p q res)
    (if(> i n)
      res
      (helper (+ i 1) (* p x) (* q i) (+ res (/ p q)))))
  (helper 1 1 1 0))
