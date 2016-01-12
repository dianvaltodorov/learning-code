#lang racket

(define (generate-N)
  (define (helper n)
    (stream-cons n
                 (helper (+ n 1))))
  (helper 0))

(define nats (generate-N))
(define ones (stream-cons 1 ones))
(define (take n s)
  (cond ((= n 0) '())
        (else (cons  (stream-first s)
                     (take (- n 1) (stream-rest s))))))

(define (take-from pos n s)
  (define (helper i s)
    (cond ((stream-empty? s) '())
          ((< i pos) (helper (+ i 1) (stream-rest s)))
          ((>= i (+ pos n)) '())
          (else (cons  (stream-first s)
                       (helper (+ i 1) (stream-rest s))))))
  (helper 0 s))


  
