(load "../../lib/unit.scm")

(define (count-digits-rec n)
  (if (<= n  9)
    1
    (+ 1 (count-digits-rec (quotient n 10)))))

(define (count-digits-iter n)
  (define (helper n result)
    (if(<= n 9)
       (+ 1 result)
       (helper (quotient n 10) (+ result 1))))
  (helper n 0))
