(define (double-factorial-iterative n)
  (define (helper i result)(
    if(>= 0 i)
      result
      (helper(- i 2)(* i result))))
  (helper n 1))

(define (double-factorial-recursive n)
  (if(<= n 0)
     1
     (* n (double-factorial-recursive (- n 2)))))

(define (fib-recursive n)
  (cond
    ((= n 0) 1)
    ((= n 1) 1)
    ((= n 2) 1)
    (else (+ (fib-recursive (- n 1)) (fib-recursive (- n 2))))))

(define (fib-recursive n)
  (cond
    ((= n 0) 1)
    ((= n 1) 1)
    ((= n 2) 1)
    (else (+ (fib-recursive (- n 1)) (fib-recursive (- n 2))))))

(define (fib-iterative n)
  (define (helper i a b)
    (if( = i n)
       a
       (helper (+ i 1) b (+ a b))))
  (helper 0 0 1))

(define (prime? n)
  (define (helper i)
    (cond
      ((> i (sqrt n)) #t)
      ((= 0 (remainder n i)) #f)
      ((helper (+ i 1)))))
  (helper 2))

(define (sum-divisors n)
 (define (helper i sum)
   (cond
     ((= i n) sum)
     ((= 0 (remainder n i)) (helper (+ i 1) (+ sum i)))
     (else (helper (+ i 1)  sum))))
 (helper 1 0))


(define (perfect? n)
  (= n (sum-divisors n)))

(define (fib-iter n)
  (define (helper i a b)
    (cond
      ((= i n) a)
      (else (helper (+ 1 i) b (+ a b)))))
