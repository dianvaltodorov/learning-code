(define mat '((1 2 3 4 10)
              (5 6 7 8 13)
              (9 8 4 3 52)
              ))

(define (get-row i m) (list-ref m i))
(define (get-column i m) (map (lambda (row) (list-ref row i)) m))
(define (remove-element l i)
  (define (helper l j)
    (cond ((null? l) '())
          ((= i j) (helper (cdr l) (+ j 1)))
          (else (cons (car l)
                      (helper  (cdr l) (+ j 1))))))
   (helper l 0))
(define (del-row m r) (remove-element m r))
(define (get-column m i) (map (lambda (row) (list-ref row i)) m))


(define (remove-occurences l x)
  (cond ((null? l) '())
        ((= x (car l)) (remove-elem (cdr l) x))
        (else (cons (car l)
                    (remove-elem (cdr l) x)))))

;(map (lambda (row) (append row (list 100))) mat)

(define (transpose mat)
  (define (helper i)
    (let ((rows-count (length mat)))
      (if (= i rows-count)
          '()
          (cons (get-column mat i)
                (helper (+ i 1))))))
  (helper 0))

(define (transpose mat)
  (define (helper i)
    (let ((columns-count (length (car mat))))
      (if (= i columns-count)
          '()
          (cons (get-column mat i)
                (helper (+ i 1))))))
  (helper 0))

(define (accumulate op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

(define (transpose-accumulate m)
  (accumulate cons
              '()
              (lambda (i) (get-column m i))
              0
              (lambda (i) (+ 1 i))
              (length (car m ))))

(list mat)
(apply map list mat)
(apply list mat)
(map list '(1 2) '(3 4))
(map list '((1 2) (3 4)))



(define (create-tree root left right) (list root left right))
(define (root t) (car t))
(define (left t) (cadr t))
(define (right t) (caddr t))


(define (insert t x)
  (cond ((null? t) (create-tree x '() '()))
        ((= x (root t)) t)
        ((< x (root t)) (create-tree (root t) (insert (left t) x) (right t)))
        (else (create-tree (root t) (left t) (insert (right t) x)))))

;(define t (insert (insert (insert '() 5) 8) -1))

(define t (insert '() 5))
(define t (insert (insert (insert (insert (insert '() 5) 8) 9) 100) 101))

(define (walk-tree t)
  (cond ((null? t) '())
        (else (append  (walk-tree (left t)) (list (root t)) (walk-tree (right t))))))
