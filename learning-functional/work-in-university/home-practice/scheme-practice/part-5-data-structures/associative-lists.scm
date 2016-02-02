(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

(define hash1 '((1 . 2) (2 . 3) (3 . 4) (8 . 4) (9 . 4)))
(define hash2 '((a . 10) (b . 12) (c . 18)))
(define hash3 '((l1 1 8) (l2 10 1 2) (l3)))
(define hash4 '((al1 (1 . 2) (2 . 3)) (al2 (b)) (al3 (a . b) (c . d))))


(define (make-alist f keys)
 (map (lambda (x) (cons x (f x))) keys))

(define al (make-alist (lambda (x) (* x x)) '(1 3 4)))

(define (keys alist) (map car alist))
(define (mvalues alist) (map cdr alist))
(define (del-key-value key alist)
  (filter (lambda (kv) (not (eq? (car kv) key))) alist))


(define (add-key-value key value alist)
  (let ((new-kv (cons key value)))
    (cond ((null? alist) (list new-kv))
          ((eq? (caar alist) key) (cons new-kv (cdr alist)))
          (else (cons (car alist)
                      (add-key-value key value (cdr alist)))))))

(define (add-key-value-slow key value alist)
  (let ((new-kv (cons key value)))
    (if (assq key alist)
        (map (lambda (kv) (if (eq? (car kv) key)
                              new-kv kv)) alist)
        (cons new-kv alist))))
