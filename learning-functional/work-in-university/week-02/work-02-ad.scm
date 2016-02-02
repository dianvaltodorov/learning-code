(define (fact n)
  (cond(( < n 2) n)
       (else (* n  (fact (- n 1))))))

(define (fact3 n)
  (define (helper i result)
      (if(> i n)
        result
        (helper (+ i 1) (* i result))))
   (helper 1 1)
  )

(define (fact3 n)
  (helper-fact3 n 1 1))

(define (helper-fact3 n i result)
    (if(> i n)
      result
      (helper-fact3 n (+ i 1) (* i result))))

(define (product-digits-iterative n)
  (define (helper n result)
    (if( <= n 9 )
      (*  n result)
      (helper (quotient n 10) (* result (remainder n 10)))))
  (helper n 1))

(define (product-digits-iterative2 n)
  (define (helper n result)
    (if( = n 0 )
       result
      (helper (quotient n 10) (* result (remainder n 10)))))
  (helper n 1))

(define (product-digits n)
  (if(< n 10) n
     (* (remainder n 10)
        (product-digits(quotient n 10)))))
