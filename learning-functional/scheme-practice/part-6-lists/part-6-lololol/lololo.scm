(define l '((1 (2)) (((3) 4) (5 (6)) () (7)) 8))

(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))

(define (count-atom l)
  (cond ((null? l) 0)
        ((atom? l) 1)
        (else (+ (count-atom (car l)) (count-atom (cdr l))))))

(define (flatten l)
  (cond ((null? l) '())
        ((atom? l) (list l))
        (else (append (flatten (car l)) (flatten (cdr l))))))

(define (deep-reverse l)
  (cond ((null? l) '())
        ((atom? l) l)
        (else (append (deep-reverse (cdr l))
                      (list (deep-reverse (car l)))))))

(define (deep-fold nv term op l)
  (cond ((null? l) nv)
        ((atom? l) (term l))
        (else (op (deep-fold nv term op (car l))
                  (deep-fold nv term op (cdr l))))))

(define (deep-fold-count-atom l)
  (deep-fold 0 (lambda (x) 1)+ l))

(define (deep-fold-flatten l)
  (deep-fold '() (lambda (x) (list x)) append l))

(define (rcons x y) (cons y x))

(define (deep-fold-reverse l)
  (deep-fold '() (lambda (x) x) rcons l))
