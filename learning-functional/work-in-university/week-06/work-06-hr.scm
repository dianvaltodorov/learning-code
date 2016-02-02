(define (member? x l)
  (cond((null? l) #f)
       ((= x (car l)) #t)
       (else (member? x (cdr l)))))

(define (mlength l)
  (if (null? l)
      0
      (+ 1  (mlength (cdr l)))))

(define (nth l n)
  (if (= n 0)
      (car l)
      (nth (cdr l) (- n 1))))

(define (my-append l1 l2)
  (if (null? l1)
      l2
      (cons (car l1) (my-append (cdr l1) l2))))

(define (gen-list n)
  (if (= n 0)
        '()
         (cons n (gen-list (- n 1)))))

(define (gen-list-reversed n)
  (define (helper i l)
    (if (> i n)
        l
        (helper (+ i 1) (cons i l))))
  (helper 1 '()))

(define (my-reverse l)
  (define (helper l res)
    (if (null? l)
        res
        (helper (cdr l) (cons (car l) res))))
  (helper l '()))

(define (union l1 l2)
  (cond ((null? l1) l2)
        ((member? (car l1) l2) (union (cdr l1) l2))
        (else (cons (car l1) (union (cdr l1) l2)))))

(define (intersection1 l1 l2)
  (define (helper all-items res)
    (cond ((null? all-items) res)
          ((and (not (member? (car all-items) res))
                (member? (car all-items) l1)
                (member? (car all-items) l2))
           (helper (cdr all-items) (cons (car all-items) res)))
          (else (helper (cdr all-items) res))))
  (helper (my-append l1 l2)'()))

(define (intersection2 l1 l2)
  (cond
    ((null? l1) '())
    ((member? (car l1) l2) (cons (car l1)
                                 (intersection2 (cdr l1) l2)))
    (else (intersection2 (cdr l1) l2))))
