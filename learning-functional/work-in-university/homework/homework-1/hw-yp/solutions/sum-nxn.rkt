#lang racket

(define (sum-nxn x n)
  (define (helper i next-pow res)
    (if(> i n)
      res
      (helper (+ i 1) (* x next-pow) (+ res (* i next-pow)))))
  (helper 1 x 0))
