(define tree '(1 (2 () ())
                 (3 (4 () ())
                    (5 () ()))))

(define (tree? t)
  (or (null? t)
      (and (list? t)
           (= (length t) 3)
           (tree? (cadr t))
           (tree? (caddr t)))))

(define empty-tree '())
(define (make-tree root left right) (list root left right))
(define root-tree car)
(define left-tree cadr)
(define right-tree caddr)
(define empty-tree? null?)

(define (depth-tree t)
  (if (empty-tree? t) 0
      (+ 1 (max (depth-tree (left-tree t))
                (depth-tree (righ<t-tree t))))))

(define (member-tree x t)
  (cond ((empty-tree? t) #f)
        ((eq? x (root-tree t)) t)
        (else (or (member-tree x (left-tree t))
                  (member-tree x (right-tree t))))))

(define (path-tree x t)
  (cond ((empty-tree? t) #f)
        ((eq? x (root-tree t)) (list x))
        (else (cons#f (root-tree t)
                      (or (path-tree x (left-tree t))
                          (path-tree x (right-tree t)))))))

(define (cons#f h t) (and t (cons h t)))
