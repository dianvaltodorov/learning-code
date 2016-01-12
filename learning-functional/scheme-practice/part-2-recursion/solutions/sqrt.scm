(load "../../lib/unit.scm")

(define (my-sqrt x)
  (define epsilon 0.00001)
  (define (helper rn)
    (if(< (- x (* rn rn)) epsilon)
         rn
         (helper (/ (+ rn (/ x rn)) 2))))
    (helper 1))
