(define (empty-tree) '())
(define (is-empty? tree) (null? tree))
(define (value tree) (car tree))
(define (left tree) (cadr tree))
(define (right tree) (caddr tree))
(define (make-tree value left right)
  (list value left right))
(define (leaf? tree)
  (and (not (is-empty? tree))
       (is-empty? (left tree))
       (is-empty? (right tree))))

(define t1 '(1 (2 () ()) (3 () ())))
(define t2 (make-tree 1 (make-tree 2 (empty-tree) (empty-tree)) (make-tree 3 (empty-tree) (empty-tree))))
(define tree (make-tree 1
                        (make-tree 2
                                   (empty-tree)
                                   (empty-tree))
                        (make-tree 3
                                   (empty-tree)
                                   (make-tree 4
                                              (empty-tree)
                                              (empty-tree)))))
;V L R
(define (traversal-pre-order tree)
  (cond ((is-empty? tree) '() )
        (else (append (list (value tree))
                      (traversal-pre-order (left tree))
                      (traversal-pre-order (right tree))))))

;L V R
(define (traversal-in-order tree)
  (if (is-empty? tree) '()
      (append (traversal-in-order (left tree))
              (list (value tree))
              (traversal-in-order (right tree)))))


;L R V
(define (traversal-post-order tree)
  (if (is-empty? tree)
      '()
      (append (traversal-post-order (left tree))
              (traversal-post-order (right tree))
              (list (value tree)))))

(define (tree-level n tree)
  (define (helper i t)
    (cond ((is-empty? t) '())
          ((= i n) (list (value t)))
          (else (append  (helper (+ i 1) (left t))
                   (helper (+ i 1) (right t))))))
  (helper 0 tree))

(define (map-tree f tree)
  (cond ((is-empty? tree) '())
        (else (list (f (value tree))
                    (map-tree f (left tree))
                    (map-tree f (right tree))))))

(map-tree (lambda(x) (* 2 x)) tree)


(define (contains-path? tree path)
  (cond ((or (null? path) (is-empty? tree)) #f)
        ((not (= (car path) (value tree))) #f)
        ((and (null? (cdr path))
              (leaf? tree)) #t)
        ((= (car path) (value tree)) (or (contains-path? (left tree) (cdr path))
                                         (contains-path? (right tree) (cdr path))))))

(define (list-paths tree)
  (cond ((leaf? tree) (value tree))
        (cons (value tree) (left tree))))
