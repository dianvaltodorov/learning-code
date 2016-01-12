(load "../../lib/unit.scm")

(load "prime.scm")

(define (sum-prime-divisors-iter x)
  (define (helper x current result)
    (cond
      ((= current x) result)
      ((and (= (remainder x current) 0)
            (prime? current)) (helper x (+ current 1) (+ current result)))
      (else (helper x (+ current 1) result))))
  (helper x 2 0))


