(load "../../lib/unit.scm")

(define (sum-digits-iter n)
  (define (helper n result)
    (if(<= n 9)
       ( + result (remainder n 10))
       (helper (quotient n 10) (+ result (remainder n 10)))))
  (helper n 0))
