#lang racket

(define (good-enough? guess x)
    (< (abs (- (cube guess) x)) 0.001))


(define (square x) 
    (* x x))


(define (cube x) 
    (* x x x))

(define (square-cube x)(square-cube-iter 1.0 x))

(define (square-cube-iter guess x)
    (if (good-enough? guess x)
        guess
        (square-cube-iter (square-cube-improve guess x)
                    x)))

(define (square-cube-improve guess x)
    (/ (+ (/ x (square guess)) (* 2 guess)) 3))

(square-cube-improve 1.0 27)


(square-cube 27)