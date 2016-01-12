(load "../../lib/unit.scm")

(define (occurrences-rec a x)
  (cond
    ((= x 0) 0)
    ((= (remainder x 10) a) (+ (occurrences-rec a (quotient x 10)) 1))
    (else (occurrences-rec a (quotient x 10)))))

(define (occurrences-iter a x)
  (define (helper a x result)
    (cond
      ((= x 0) result)
      ((= (remainder x 10) a) (helper a (quotient x 10) (+ result 1)))
      (else (helper a (quotient x 10) result))))
  (helper a x 0))
