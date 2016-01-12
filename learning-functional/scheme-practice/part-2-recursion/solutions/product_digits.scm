(load "../../lib/unit.scm")

(define (product-digits-rec n)
  (if(< n 10) n
     (* (remainder n 10)
        (product-digits-rec (quotient n 10)))))

(define (product-digits-iter n)
  (define (helper n result)
    (if( <= n 9 )
      (*  n result)
      (helper (quotient n 10) (* result (remainder n 10)))))
  (helper n 1))

(define (product-digits-iter2 n)
  (define (helper n result)
    (if( = n 0 )
       result
      (helper (quotient n 10) (* result (remainder n 10)))))
  (helper n 1))
