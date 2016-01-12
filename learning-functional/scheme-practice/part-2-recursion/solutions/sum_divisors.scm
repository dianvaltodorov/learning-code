(load "../../lib/unit.scm")

(define (sum-divisors-iter x)
  (define (helper x current result)
    (cond
      ((= current x) result)
      ((= (remainder x current) 0) (helper x (+ current 1) (+ current result)))
      (else (helper x (+ current 1) result))))
  (helper x 1 0))
