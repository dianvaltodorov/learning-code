(load "../../lib/unit.scm")

(define (factorial-rec n)
  (if(= n 1)
     1
     (* n  (factorial-rec (- n 1)))))

(assert (factorial-rec 3) 6)
(assert (factorial-rec 4) 24)


(define (factorial-iter n)
  (define (helper current res)
    (if(= current 1)
       res
       (helper (- current 1) (* current res ))))
  (helper n 1))
