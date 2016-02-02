(define (begins-with? l1 l2)
  (cond
    ((null? l2) #t)
    ((null? l1) #f)
    ((not (= (car l1)(car l2))) #f)
    (else (begins-with? (cdr l1) (cdr l2)))))

(define (count-occurences-i l1 l2)
 (define (helper res l)
   (cond ((null? l) res)
         ((begins-with? l l2) (helper (+ res 1) (cdr l)))
         (else (helper res (cdr l)))))
  (helper 0 l1))

(define (count-occurences-rec l1 l2)
 (cond
   ((null? l1) 0)
   ((begins-with? l1 l2) (+ 1 (count-occurences-rec (cdr l1) l2)))
   (else (count-occurences-rec (cdr l1) l2))))

(count-occurences-rec '(1 2 7 3 1 2 4 2 1 2) '(1 2))

(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))

(define (member-deep? x l)
  (cond ((null? l) #f)
        ((atom? l) (= l x))
        (else (or (member-deep? x (car l)) (member-deep? x (cdr l))))))

(define (memeber-deep? x l)
  (cond
    ((null? l) #f)
    ((list? (car l)) (or(member-deep x (car l))
                        (member-deep x (cdr l))))
    ((=(car l) x) #t)
    (else (member-deep x (cdr l)))))

(define l1 '((1 (2)) (((3) 4) (5 (6)) () (7)) 8))
(define l2 '(1 2 (3 7 ( 4 5 2) 8) 3))
(member-deep? 2 l2)
(member-deep? 100 l2)
(member-deep? 2 l1)
(member-deep? 100 l2)

(define (generate-list n)
  (define (helper i result)
    (if (> i n)
        result
        (helper (+ i 1) (cons i result))))
  (helper 1 '()))


(define (generate-list-rev n)
  (define (helper i result)
    (if (= i 0)
        result
        (helper (- i 1) (cons i result))))
  (helper n '()))


(define (construct-list n)
  (define (helper n res)
    (if (= n 0)
        res
        (helper (- n 1) (append res (list (generate-list n))))))
  (helper 10 '()))

(define (construct-list n)
  (if (= n 0)
      '()
      (cons (generate-list n)
            (construct-list (- n 1)))))

(construct-list 10)

;(define (cartesian-produc l1 l2))

(define l1 '(1 2 3 4 5 6))
(define l2 '(7 8 9))

(define (cartesian-product l1 l2)
  (map (lambda (x) (map (lambda (i) (list x i)) l2)) l1))

(define (flatten l)
  (cond ((null? l) '())
        ((atom? l) (list l))
        (else (append (flatten (car l)) (flatten (cdr l))))))

(flatten '((1 (2)) (((3) 4) (5 (6)) () (7)) 8))

(define mat '((1 2 3) (4 5 6) (7 8 9)))
(define (get-row mat) (car mat))
(define (get-col mat) (map (lambda (row) (list-ref row)) mat))
(define (get-diagonal mat) (map (lambda (row) (car row)) mat))
(get-row mat)
(get-col mat)
(define (diagonal mat)
  (define helper n
