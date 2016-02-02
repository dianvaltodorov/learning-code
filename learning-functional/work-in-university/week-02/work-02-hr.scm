(define (count-digits n)
  (if (<= n  9)
    1
    (count-digits (quotient n 10))))

(define (count-digits-iter n)
  (define (count-digits-iter-helper n result)
    (if(<= n 9)
       (+ 1 result)
       (count-digits-iter-helper (quotient n 10) (+ result 1)))
  (count-digits-iter-helper n 0))

(define (sum-digits n)
  (define (sum-digits-helper n result)
    (if(<= n 9)
       ( + result (remainder n 10))
       (sum-digits-helper (quotient n 10) (+ result (remainder n 10)))))
  (sum-digits-helper n 0))

(define (prime? n)
  (define (prime-helper n divisor)
    (cond
      ((> divisor (sqrt n)) #t)
      ((= 0 (remainder n divisor)) #f)
      (else (prime-helper n (+ divisor 1)))))
  (prime-helper n 2))

(define (automorphic? n)
  ( = n (remainder (expt n 2) (expt 10 (count-digits n)))))

(define (sum start end)
  (if (>= start end)
      end
     (+ start (sum (+ start 1) end))))
