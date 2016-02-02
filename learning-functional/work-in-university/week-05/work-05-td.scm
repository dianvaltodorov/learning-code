(cons 1 2)
(cons 1 '())
(list 1 2 3)
(list '())
(list? (cons 1 2))
(list? (cons 1 (cons 2 4)))
(list? (cons 1 (cons 2 '())))

(cons 1 (cons 2 3))
(cons 1 (cons 2 ( cons 3 '())))
(cons 1 (cons 2 ( cons (cons 3 '()) '())))
(list 1 2 3 4)
(list 1 2 3 '(4))

(define (list-digits n)
  (if(< n 10)
     (cons n '())
     (cons (remainder n 10) (list-digits (quotient n 10)))))


(define (list-digits-i n)
  (define (helper l cur)
    (if(< cur 10)
       (cons cur l)
       (helper (cons (remainder cur 10) l) (quotient cur 10))))
  (helper '() n))

(define (list-divisors-i n)
  (define (helper l i)
    (cond ((> i (/ n 2)) l)

          ((= 0 (remainder n i)) (helper (cons i l)
                                         (+ i 1)))
          (else (helper l
                        (+ i 1)))))
       (helper '() 1))

(define (push_back n l)
  (if(null? l)
     (cons n '())
     (cons (car l) (push_back n (cdr l)))))

(define (count-occurences n l)
  (define (helper res lst)
    (cond ((null? lst) res)
          (( = (car lst) n) (helper (+ 1 res) (cdr lst)))
          (else (helper res (cdr lst)))))
  (helper 0 l))

(define (n-th n l)
  (define (helper i lst)
    (if(= i n)
       (car lst)
       (helper (+ i 1) (cdr lst))))
  (helper 0 l))

(define (mmap f l)
  (if(null? l)
     '()
      (cons (f (car l)) (mmap f (cdr l)))))

(define (mfilter p? l)
  (cond ((null? l)'())
        ((p? (car l)) (cons (car l) (mfilter p? (cdr l))))
        (else (mfilter p? (cdr l)))))

(define (reduce-i op null-value l)
  (define (helper res l)
    (if(null? l)
       res
       (helper (op res (car l)) (cdr l))))
  (helper null-value l))

(define (reduce op null-value l)
  (if(null? l)
     null-value
     (op (car l) (reduce op null-value (cdr l)))))

(define (filter-reduce op pred? null-value l)
  (cond ((null? l) null-value)
        ((pred? (car l)) (op (car l)
                             (filter-reduce op pred? null-value (cdr l))))
        (else (filter-reduce op pred? null-value (cdr l)))))

(define (sum-odd-sq l)
  (filter-accumulate + odd? 0 (mmap (lambda (x) (* x x)) l)))

(define htl (list 1 '(1 2 3) "hello" 2+3i 3.14 "world" "Hello world"))

(filter-reduce string-append string? "!" htl )

(define (concat-cons l1 l2)
  (filter-reduce cons (lambda (x) #t) l2 l1))

(define (concat-pb l1 l2)
  (filter-reduce push_back (lambda (x) #t) l1 l2))

(define (mreverse l)
  (reduce-i push_back '() l))
