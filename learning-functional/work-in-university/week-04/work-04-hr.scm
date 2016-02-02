(define (accumulate start end next term comb initial)
  (define (helper current res)
    (if(> current end)
       res
       (helper (next current) (comb res (term current)))))
  (helper start initial))

(define (fact n)
  (accumulate 1 n (lambda (x) (+ x 1)) (lambda (x) x) * 1))

(define (pow x n)
  (accumulate 1 n (lambda (x) (+ x 1)) (lambda (_) x) * 1))

(define (variation n k)
  (/ (fact n) (fact (- n k))))

(define (combination n k)
  (/ (fact n) (* (fact k)(fact (- n k)))))

(define (expo x)
  (accumulate 0
              10000000
              (lambda (x) (+ x 1))
              (lambda (n) (/ (pow x n) (fact n)))
              +
              0))

(define (sine x)
  (accumulate 0
              100
              (lambda (x) (+ x 1))
              (lambda (n) (* (pow -1 n)
                             (/ (pow x (+ (* 2 n) 1))
                                (fact (+ (* 2 n) 1)))))
              +
              0))

(sine (/ 3.1415 2))
(sine 0)

(define (cosine x)
  (accumulate 0
              100
              (lambda (x) (+ x 1))
              (lambda (n) (* (pow -1 n)
                             (/ (pow x (* 2 n))
                                (fact (* 2 n)))))
              +
              0))

(define (prime? n)
  (accumulate ))

;(reverse n)
;(sqrt x)
