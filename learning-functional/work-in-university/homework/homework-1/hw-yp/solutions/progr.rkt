#lang racket

(define (progr n)
  (define (helper current)
    (cond ((< current  10) #t)
          ((< (remainder current 10)
              (remainder (quotient current 10) 10)) (helper (quotient current 10)))
          (else #f)))
  (helper n))
