(load "../../lib/unit.scm")

(define (double-factorial-iter n)
  (define (helper i result)(
    if(>= 0 i)
      result
      (helper(- i 2)(* i result))))
  (helper n 1))

(define (double-factorial-rec n)
  (if(<= n 0)
     1
     (* n (double-factorial-rec (- n 2)))))
