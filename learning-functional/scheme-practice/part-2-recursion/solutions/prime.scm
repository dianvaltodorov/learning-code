(load "../../lib/unit.scm")

(define (prime? x)
  (define (helper x current)
    (cond
      ((= current x) #t)
      ((= (remainder x current) 0) #f)
      (else (helper x (+ current 1)))))
  (helper x 2))
