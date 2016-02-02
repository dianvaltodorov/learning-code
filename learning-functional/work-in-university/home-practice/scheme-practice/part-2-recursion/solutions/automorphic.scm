(load "count_digits.scm")

(define (automorphic? n)
  ( = n (remainder (expt n 2) (expt 10 (count-digits-iter n)))))
