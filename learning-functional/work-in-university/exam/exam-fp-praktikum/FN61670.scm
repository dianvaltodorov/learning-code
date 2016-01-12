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


;Task 1:
(define A '(1 2 3 4 5))
(define B '(2 4 5 9 19 10 12))

(define (intersection A B)
  (define (helper lst res)
    (cond ((null? lst) res)
          ((and (member (car lst) A)
                (member (car lst) B)
                (not (member (car lst) res))) (helper (cdr lst) (cons (car lst) res)))
          (else (helper (cdr lst) res))))
  (helper (append A B) '()))

(define (union A B)
  (define (helper res lst)
    (cond((null? lst) res)
         ((member (car lst) res)(helper res (cdr lst)))
         (else (helper (cons (car lst) res) (cdr lst)))))
  (helper A B))


(define (razlika A B)
  (define (helper lst res)
    (cond ((null? lst) res)
          ((and (member (car lst) A)
                (not (member (car lst) B))) (helper (cdr lst) (cons (car lst) res)))
          (else (helper (cdr lst) res))))
  (helper (union A B) '()))

;Task 2:
(define (f x) (* x x))
(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16))
(define (zad-2 f lst)
    (filter (lambda (x) (member (f x) lst)) lst))

(zad-2 f lst)
;Task 3:

(define (successors g v)
  (cadr (assoc v g)))

(define (parents g v)
  (map (lambda(filtered-entry) (car filtered-entry)) (filter (lambda (entry) (member v (cadr entry))) g)))

(define (number-successors g v)
  (length (successors g v)))

(define (number-parents g v)
  (length (parents g v)))


(define g '((1 (2))
            (2 (5 6 7 9 10))
            (3 (1 2))
            (4 ())
            (5 (2))
            (6 (4))))

(successors g 2)
(parents g 2)
(number-successors g 4)
(number-parents g 2)

(define v 2)


(or
 (and(<= (number-successors g v) 1)
     (<= (number-parents g v) 1))
 (and (<= (number-parents g v) 1)


(if (> (number-successors g v) 1)
    (if

(define (chinese-vert? g v)
  (if (>= (length (adj g v) 2)
          (= (length (filter (lambda(p)(= (length (adj g p) 1))) (parents g v)))
              (length (parens g v)))
          #t)))

(define (chinese? g)
  (= (length (filter  (lambda (v) (chinese-vert? g v)) vertices g))
      (length (vertices g ))))
