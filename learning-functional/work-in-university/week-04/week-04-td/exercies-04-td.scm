(define (1+ x)(+ x 1))
(define (id x) x)
(define (cube x) (* x x x))
(define (times2 x) (* x 2))

;curying
(define (add3)
  (lambda (x) (+ x 3)))

(define (compose f g)
  (lambda(x) (f (g x))))

;((compose times2 cube) 3)

(define (accumulate-i op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))


(define (apply-twice f)
  (lambda (x) (f (f x))))

(define (apply-n n f)
  (lambda(x)
    (define(helper n)
      (if(= n 1)
         (f x)
         (f(helper (- n 1)))))
    (helper n)))


((apply-n 7 1+) 4)


(define (sum-evens a b)
  (accumulate-i +
                0
                (lambda (x) x)
                a
                (apply-twice 1+)
                b))

;(sum-evens 0 8)

(define (count-divisors a)
  (accumulate-i +
                0
                (lambda (i) (if(= 0 (remainder a i)) 1 0))
                1
                (lambda (i) (+ i 1))
                a))


(define (sum-d-divisors a b d)
  (accumulate-i +
                0
                (lambda(x) (if(= d (count-divisors x)) x 0))
                a
                (lambda(x) (+ 1 x))
                b))

(define (accum-perfect? n)
  (= n (accumulate-i +
                     0
                     (lambda (i) (if(= 0 (remainder n i))
                                    i
                                    0))
                     1
                     (lambda (i) (+ i 1))
                     (/ n 2))))

(define (product-perfect a b)
  (accumulate-i *
                1
                (lambda(x) (if(accum-perfect? x) x 1))
                a
                (lambda (i) (+ i 1))
                b))

(define (product-x-over-x-plus-n x n)
  (accumulate-i *
                1
                (lambda(i) (/ x (+ x i)))
                0
                (lambda (i) (+ i 1))
                n))

(define (sum-product-x-over-x-plus-n x n)
  (accumulate-i +
                0
                (lambda(i) (product-x-over-x-plus-n x i))
                0
                (lambda (i) (+ i 1))
                n))

(define (mmap f list)
  (if(null? list)
     '()
     (cons (f (car list)) (mmap f (cdr list)))))

;ДР  (sum-all-even-cubes list)
