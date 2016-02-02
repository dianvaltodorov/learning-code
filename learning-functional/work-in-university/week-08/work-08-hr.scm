(define (filter p l)
  (define (helper current-l result)
    (cond
      ((null? current-l) result)
      ((p (car current-l)) (helper (cdr current-l)
                                   (append result (list (car current-l)))))
      (else (helper (cdr current-l) result))))
  (helper l '()))

(define (accumulate l term comb initial)
  (define (helper current-l result)
    (if (null? current-l)
        result
        (helper (cdr current-l)
                (comb result (term (car current-l))))))
  (helper l initial))


(define mat '((1 2 3)
              (5 6 7)
              (8 9 10)))
;============================================================
(define (get-first-row m) (car m))
(define (get-first-column m) (map car m))
(define (get-nth-row m n) (list-ref m n))
(define (get-nth-column m n) (map (lambda (row) (list-ref row n)) m))
(define (filter-matrix p m) (map (lambda (row) (filter p row)) m))

(define (diagonal1 m)
  (define (helper i mat)
    (if(null? mat)
       '()
       (cons (list-ref (car mat) i) (helper (+ i 1) (cdr mat)))))
  (helper 0 mat))


(define (diagonal1-optimized m)
  (if(null? m)
  '()
  (cons (caar m) (diagonal1-optimized (map cdr (cdr m))))))


(define (diagonal2 m)
  (define (helper i mat)
    (if(null? mat)
       '()
       (cons (list-ref (car mat) i) (helper (- i 1) (cdr mat)))))
  (helper (- (length (car mat)) 1) mat))

(define (diagonal2-optimized m)
  (if(null? m)
  '()
  (cons (car (car m)) (diagonal1-optimized (map cdr (cdr m))))))

(define (skip-row m r)
  (define (helper i m)
    (cond ((null? m) '())
          ((= i r) (helper (+ i 1) (cdr m)))
          (else  (cons (car m) (helper (+ i 1) (cdr m))))))
  (helper 0 m))

(define (remove-nth-element n l)
  (define (helper i l)
    (cond ((null? l) '())
          ((= i n) (helper (+ i 1) (cdr l)))
          (else (cons (car l
                           ) (helper (+ i 1) (cdr l))))))
  (helper 0 l))

(define (skip-column m c)
  (map (lambda (row) (remove-nth-element c row)) m))

(define (skip-row-column m r c)
  (skip-column (skip-row m r) c))

(define (transpose m)
       (apply map list m))

(define (transpose2 m)
  (define (helper i)
    (if (= i (length m))
        '()
        (cons (get-nth-column m i)
              (helper (+ i 1)))))
  (helper 0))

(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))

(cons 3 '(1 2 3))
(cons 3 (cons 2 '(1 2 3 4)))

(define (insert-after-deep l)
  (cond
    ((null? l) l)
    ((list? (car l)) (cons
                       (insert-after-deep (car l))
                       (insert-after-deep (cdr l))))
    ((even? (car l)) (cons (car l) (cons
                                  10
                                  (insert-after-deep (cdr l))) ))
    (else (cons (car l)
                (insert-after-deep (cdr l))))))


(insert-after-deep '(1 ((2) 3 4) (((5))) 6 7)) ;-> (1 ((2 10) 3 4 10) (((5))) 6 10 7)



(define (flatten m)
        (apply append m))
