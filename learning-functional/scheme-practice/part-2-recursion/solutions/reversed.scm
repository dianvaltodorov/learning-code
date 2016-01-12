(load "../../lib/unit.scm")

(define (reversed-iter n)
   (define (helper current result)
     (if(= current 0)
          result
          (helper (quotient current 10)
                  (+ (* result 10) (remainder current 10)))))
   (helper n 0))
