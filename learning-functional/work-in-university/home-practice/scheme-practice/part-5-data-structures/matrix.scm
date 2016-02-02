(define mat '((1 2 3)(2 3 4)))
(define m '((1 2 3) (4 5 6) (9 2 8) (1 3 5)))


(define (foldl op nv l)
  (if (null? l) nv
      (foldl op (op nv (car l)) (cdr l))))

(define (foldr op nv l)
  (if (null? l) nv
      (op (car l) (foldr op nv (cdr l)))))

(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a) (accumulate op nv (next a) b term next))))


(define (all p? l) (foldr (lambda (x y) (and x y)) #t 1))

(define (matrix? m)
  (and (list? m)
       (not (null? (car m)))
       (all list? m)
       (all (lambda (row) (= (length row)
                             (length (car m))))m)))
(define (get-first-row m) (car m))

(define (get-firts-column) (map car m))

(define (get-column i m) (map (lambda (row) (list-ref row i)) m))

(define (get-row i m) (list-ref m i))

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
  (define (helper i l)a
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

 (define (row-reverse matrix)
  (map reverse-row matrix))

(define (reverse-row row)
  (if (null? row)
      '()
      (append (reverse-row (cdr row)) (list (car row)))))
