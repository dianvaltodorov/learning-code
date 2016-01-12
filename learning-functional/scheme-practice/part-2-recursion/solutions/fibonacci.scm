(load "../../lib/unit.scm")

(define (fib-rec n)
  (cond
    ((= n 0) 1)
    ((= n 1) 1)
    ((= n 2) 1)
    (else (+ (fib-rec (- n 1)) (fib-rec (- n 2))))))

(define (fib-iter n)
  (define (helper i a b)
    (if( = i n)
       a
       (helper (+ i 1) b (+ a b))))
  (helper 0 0 1))
