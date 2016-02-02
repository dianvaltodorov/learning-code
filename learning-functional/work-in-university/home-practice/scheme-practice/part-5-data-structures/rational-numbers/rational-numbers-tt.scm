(define (accumulate op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

(define (make-rat n d)
  (cons 'rat
        (if (or (= d 0) (= n 0)) (cons 0 1)
            (let* ((g (gcd n d))
                   (ng (quotient n g))
                   (dg (quotient d g)))
              (if (> dg 0) (cons ng dg)
    (cons (- ng) (- dg)))))))

(define (rat? p)
  (and (pair? p) (eq? (car p) 'rat)
       (pair? (cdr p)) (number? (cadr p)) (number? (cddr p))))

(define get-numer cadr)
(define get-denom cddr)

(define (*rat p q)
  (make-rat (* (get-numer p) (get-numer q))
            (* (get-denom p) (get-denom q))))

(define (+rat p q)
  (make-rat (+ ( * (get-numer p)
                   (get-denom q))
               (* (get-denom p)
                  (get-numer q)))
            (*(get-denom p) (get-denom q))))

(define (<rat p q)
  (< (* (get-numer p) (get-denom q))
   (* (get-numer q) (get-denom p))))

(define x (make-rat 2 3))
(define y (make-rat 5 8))


(define (make-rat n d)
  (let* ((g (gcd n d))
         (numer (quotient n g))
         (denom (quotient d g)))
    (lambda (prop)
      (case prop
        (’get-numer numer)
        (’get-denom denom)
        (’print (cons numer denom))))))

(define r1 (make-rat 3 4))
(r1 'get-numer)
