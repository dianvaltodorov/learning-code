(load "../../lib/unit.scm")

(define (contains-digits? a b)
  (define (has-digit? a digit)
    (define (helper current)
      (cond
        ((= current 0) #f)
        ((= digit (remainder current 10)) #t)
        (else (helper (quotient current 10)))))
    (helper a))
  (define (helper current)
    (cond
      ((= current 0 ) #t)
      ((has-digit? a (remainder current 10)) (helper (quotient current 10)))
      (else #f)))
  (helper b))
