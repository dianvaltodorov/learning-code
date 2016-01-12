(load "../../lib/unit.scm")

(define (to-binary n)
  (define (special-reversed n)
    (define (helper current res)
      (if(= current 0)
         res
         (helper (quotient current 10) (+ (* res 10)(-(remainder current 10) 1)))))
    (helper n 0))
  (define (helper current result)
    (if(= current 0)
      (special-reversed result)
      (helper (quotient current 2) (+ (* result  10) (+ 1 (remainder current 2))))))
  (helper n 0))
