(define (mcons a b)
  (lambda (f)
    (if(eq? f "car")
       a
       b)))

(define (mcar pair) (pair "car"))
(define (mcdr pair) (pair "cdr"))

(define yolo  (mcons 2 (mcons 3 (mcons 4 5))))
((mcdr yolo) "car")
(mcdr yolo)
(mcar (mcdr yolo))
