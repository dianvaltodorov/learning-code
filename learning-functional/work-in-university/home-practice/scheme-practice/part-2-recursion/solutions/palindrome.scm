(load "../../lib/unit.scm")

(load "reversed.scm")

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

(define (count-palindromes-iter2 start end)
  (define (helper i result)
    (if(> i end)
       result
       (helper (+ i 1)
               (+ result
                  (if (palindrome? i)
                      1
                      0)))))
  (helper start 0))
