#lang racket

(define (gcd x y)
  (define (helper a b)
    (cond ((= a b) a)
          ((> a b) (helper (- a b) b))
          ((< a b) (helper a (- b a)))))
  (helper x y))

(define (scd x y)
  (/ (* x y) (gcd x y)))

(define (exp x n)
  (define (helper i p q res)
    (if(> i n)
      res
      (helper (+ i 1) (* p x) (* q i) (+ res (/ p q)))))
  (helper 1 1 1 0))


(define (progr n)
  (define (helper current)
    (display current)
    (newline)
    (cond ((< current  10) #t)
          ((< (remainder current 10)
              (remainder (quotient current 10) 10)) (helper (quotient current 10)))
          (else #f)))
  (helper n))


(define (sum-nxn x n)
  (define (helper i next-pow res)
    (if(> i n)
      res
      (helper (+ i 1) (* x next-pow) (+ res (* i next-pow)))))
  (helper 1 x 0))
