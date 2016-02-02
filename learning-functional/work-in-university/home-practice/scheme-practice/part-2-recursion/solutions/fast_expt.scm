(load "../../lib/unit.scm")

(define (fast-exp x n)
  (cond
    ((= n 0) 1)
    ((even? n) (* (fast-exp x (/ n 2)) (fast-exp x (/ n 2))))
    (else (* x (fast-exp x (- n 1))))))
