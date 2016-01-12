(load "../../lib/unit.scm")

(load "ends_with.scm")
(load "count_digits.scm")

(define (substr? a b)
  (define (helper current)
    (cond
      ((< current (expt 10 (count-digits-iter b))) #f)
      ((ends-with? current b) #t)
      (else (helper(quotient current 10)))))
  (helper a))
