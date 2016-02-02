(load "../../lib/unit.scm")

(load "sum_divisors.scm")

(define (is-perfect? x)
  (= x (sum-divisors x)))
