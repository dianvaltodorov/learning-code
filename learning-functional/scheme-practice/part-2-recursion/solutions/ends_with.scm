(load "../../lib/unit.scm")

(load "count_digits.scm")

(define (ends-with? a b)
   ( = b
       (remainder a (expt 10 (count-digits-iter b)))))
