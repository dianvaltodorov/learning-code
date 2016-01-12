#lang racket

;Зад.7. Да се напише функция (fast-expt x n), която
;изчислява xn по метода на бързата експонента:
;ако n=2k (четно число), то xn = (x2)k. Aко n=2k+1
;(нечетно), то xn = x.(x2)k. Тук и рекурсивното
;повдигане на k-та степен също трябва да се извърши
;"бързо", т.е. по същия метод.

(define (fast-expt x n)
  (cond ((= n 0) 1)
  ((= 0 (remainder n 2)) (* (fast-expt x (/ n 2)) (fast-expt x (/ n 2))))
  ((= 1 (remainder n 2)) (* x (fast-expt x (- n 1))))))



(define (increasing? x)
  (define (helper previous-digit current)
    (cond
      ((= current 0) #t)
      ((<= previous-digit (remainder current 10)) #f)
      (else (helper (remainder current 10) (quotient current 10)))))
  (helper (remainder x 10)(quotient x 10)))

(increasing? 12345)
(increasing? 54321)
(increasing? 987)
(increasing? 567)
