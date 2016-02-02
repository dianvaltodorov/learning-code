(define (accumulate-rec op null-value term a next b)
  (if(> a b)
     null-value
     (op (term a) (accumulate op null-value term (next a) next b))))

(define (accumulate-i op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

(define (filter-accum-rec pred? op null-value term a next b)
  (cond ((> a b) null-value)
        ((pred? a) (op (term a)
                       (filter-accum-rec pred?
                                         op
                                         null-value
                                         term
                                         a
                                         next
                                         b)))
        (else (filter-accum-rec pred?
                                op
                                null-value
                                term
                                a
                                next
                                b))))

(define (filter-accum-i pred? op null-value term a next b)
  (define (helper i res)
     (cond ((> i b) res)
           ((pred? i) (helper (next i) (op res (term i))))
           (else (helper (next i) res))))
  (helper a null-value))

(define (fact-accum n)
  (accumulate-i *
                1
                (lambda (x) x)
                1
                (lambda (x) (+ x 1))
                n))

(define (expt-accum x n)
  (accumulate-i *
                1
                (lambda (i) x)
                1
                (lambda (x) (+ x 1))
                n))

(define (count-divisors n a b)
  (accumulate-i +
                0
                (lambda (i) (if(= 0 (remainder n i)) 1 0))
                a
                (lambda (i) (+ i 1))
                b))

(define (count-fixed f a b)
  (accumulate-i +
                0
                (lambda (i) (if(= i (f i)) 1 (0)))
                a
                (lambda (i) (+ i 1))
                b))

(define (powers-sum x n)
  (accumulate-i +
                0
                (lambda (i) (expt x i))
                1
                (lambda (i) (+ i 1))
                n))

(define (func-sum f n)
  (accumulate-i +
                0
                f
                1
                (lambda (i) (+ i 1))
                n))

(define (combinations n k)
  (/ (accumulate-i *
                   1
                   (lambda (x) x)
                   1
                   (lambda (x) (+ x 1))
                   n)
       (* (accumulate-i *
                        1
                        (lambda (x) x)
                        1
                        (lambda (x) (+ x 1))
                        k)
          (accumulate-i *
                        1
                        (lambda (x) x)
                        1
                        (lambda (x) (+ x 1))
                        (- n k)))))

(define (prime? n)
 (= 0 (accumulate-i +
                    0
                    (lambda (i) (if (= 0 (remainder n i)) 1 0))
                    2
                    (lambda (i) (+ i 1))
                    (sqrt n))))

(define (perfect-accum n)
  (= n (accumulate-i *
                     1
                     (lambda (i) (if(= 0 (remainder n i)) i 0))
                     1
                     (lambda (i) (+ i 1))
                     (/ n 2))))

(define (integrate f a b dx)
  (= n (accumulate-i +
                     0
                     (lambda(i) (* dx (f x)))
                     a
                     (lambda (i) (+ i dx))
                     b)))

(define (sum-divisors n)
  (accumulate-i +
                0
                (lambda (i) (if(= 0 (remainder n i)) i 0))
                1
                (lambda (i) (+ i 1))
                (/ n 2)))


(define (pow x n)
  (accumulate-i *
                1
                (lambda (i) x)
                1
                (lambda (i) (+ i 1))
                n))

(define (variation n k)
  (accumulate-i *
                1
                (lambda (x) x)
                1
                (lambda (x) (+ x 1))
                (+ 1 (n - k))))

(define (expo x)
  (accumulate-i 0
                10000000
                (lambda (i) (/ (pow x i) (fact i)))
                0
                (lambda (i) (+ i 1))
                10000000))

(define (sine x)
  (accumulate-i +
                0
                (lambda (i) (* (pow -1 i)
                               (/ (pow x (+ (* 2 i) 1))
                                  (fact-accum (+ (* 2 i) 1)))))
                0
                (lambda (i) (+ i 1))
                100))

(define (cosine x)
  (accumulate-i +
                0
                (lambda (i) (* (pow -1 i)
                               (/ (pow x (* 2 i))
                                  (fact-accum (* 2 i)))))
                0
                (lambda (i) (+ i 1))
                100))

(define (compose f g)
        (lambda(x) (f (g x))))


(define (count-digits-iter n)
  (define (helper current result)
   (if (<= current 0)
       result
       (helper (quotient current 10)
               (+ result 1))))
  (helper n 0))

(define (mreverse n)
  (accumulate-i (lambda (res value) (+ (* res 10)  value))
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
