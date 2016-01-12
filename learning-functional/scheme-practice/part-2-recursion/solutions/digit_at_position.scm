(load "../../lib/unit.scm")

(load "fast_expt.scm")
(load "count_digits.scm")

(define (digit-at-pos x position)
  (remainder (quotient x
                       (fast-exp 10
                                 (- (count-digits-iter  x)
                                    position)))
             10))
