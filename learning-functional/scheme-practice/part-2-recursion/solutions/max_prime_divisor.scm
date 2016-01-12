(load "../../lib/unit.scm")

(load "prime.scm")

(define (max-prime-divisor-iter x)
  (define (helper x current max)
    (cond
      ((= x current) max)
      ((and (= (remainder x current) 0) (prime? current) (> current max)) (helper x (+ current 1) current))
      (else (helper x (+ current 1) max))))
  (helper x 2 0))
