(define (f x)
  (* (+ x 4) (+ x 5)))

(define (f x)
  (define x-plus-3 (+ x 3))
  (define x-plus-5 (+ x 3))
  (* x-plus-3 x-plus-4))


(define (f1 x)
    (define x-plus-3 (+ x 3))
    (define x-plus-5 (+ x 3))
    (* x-plus-3 x-plus-4))

(define (f2 x)
  ((lambda (xplus3 xplu5)
    (* xplus xplu5))
    (+ x 3)  (+ x 5)))

(define (f3 x)
  (let ((x-plus-3 (+ x 3))
        (x-plus-5 (+ x 3)))
    (* x-plus-3 x-plus-5)))

(define (f x)
    (let* ((x-plus-3 (+ x 3))
          (x-plus-5 (+ x-plus-3 2)))
      (* x-plus-3 x-plus-5)))

(define (is-even? n)
  (letrec
      ((my-even? (lambda (n)
                   (if (= n 0)
                       #t
                       (my-odd? (-n 1))))))))


(define (accumulate-i op null-value term a next b)
 (define (helper i res)
   (if(> i b)
      res
     (helper (next i) (op res (term i)))))
 (helper a null-value))

(define (count-digits-iter n)
 (define (helper current result)
   (if (<= current 0)
       result
       (helper (quotient current 10)
               (+ result 1))))
 (helper n 0))


 (define (mreverse n)
   (accumulate-i (lambda (res _) (+ (* res 10)  value))
                 0
                 (lambda (i) (remainder (quotient n (expt 10 i)) 10))
                 0
                 (lambda (i) (+ i 1))
                 (- (count-digits-iter n) 1)))

 (define (my-sqrt x)
   (exact->inexact(accumulate-i (lambda (res value)(/ (+ res (/ x res)) 2))
                                1
                                (lambda (i) 0)
                                1
                                (lambda (i) (+ i 1))
                                10)))
