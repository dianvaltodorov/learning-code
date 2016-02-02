(define (accumulate op null-value term a next b)
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

(define (deep-fold nv term op l)
  (cond ((null? l) nv)
      ((atom? l) (term l))
      (else (op (deep-fold nv term op (car l))
                (deep-fold nv term op (cdr l))))))


(define (foldr op nv l)
    (if (null? l)
        nv
        (op (car l) (foldr op nv (cdr l)))))

(define (foldl op nv l)
  (if (null? l)
        nv
        (foldl op (op nv (car l)) (cdr l))))

(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))
