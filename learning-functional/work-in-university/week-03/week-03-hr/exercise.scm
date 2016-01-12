(define (reversed-iter n)
  (define (helper current result)
    (if(= current 0)
         result
         (helper (quotient current 10)
                 (+ (* result 10) (remainder current 10)))))
  (helper n 0))


(define (palindrome? n)
  (if(= 0 (remainder n 10))
    #f
    (= n (reversed-iter n))))

(define (count-palindromes-iter start end)
  (define (helper i result)
    (cond
      ((> i end) result)
      ((palindrome? i) (helper (+ i 1) (+ 1 result)))
      (else (helper (+ i 1) result))))
  (helper start 0))

(define (count-palindromes-iter start end)
  (define (helper i result)
    (if(> i end)
       result
       (helper (+ i 1)
               (+ result
                  (if (palindrome? i)
                      1
                      0)))))
  (helper start 0))

(define (number-of-digits x)
    (define (helper x result)
      (if(= x 0)
         result
         (helper (quotient x 10) (+ 1 result))))
    (helper x 0))

(define (ends-with? a b)
   ( = b
       (remainder a (expt 10 (number-of-digits b)))))


(define (substr? a b)
  (define (helper current)
    (cond
      ((< current (expt 10 (number-of-digits b))) #f)
      ((ends-with? current b) #t)
      (else (helper(quotient current 10)))))
  (helper a))


(define (my-sqrt x)
  (define epsilon 0.00001)
  (define (helper rn)
    (if(< (- x (* rn rn)) epsilon)
         rn
         (helper (/ (+ rn (/ x rn)) 2))))
  (helper 1))
