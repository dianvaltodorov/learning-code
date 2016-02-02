(define empty-tree '())
(define (make-tree root left right) (list root left right))
(define root-tree car)
(define left-tree cadr)
(define right-tree caddr)
(define empty-tree? null?)


(define (depth-tree t)
  (if (empty-tree? t) 0
      (+ 1 (max (depth-tree (left-tree t))
                (depth-tree (right-tree t))))))

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


(define (children t)
  (if (empty-tree? t)
      '()
      (append (if (not (empty-tree? (left-tree t)))
                  (list (root-tree (left-tree t)))
                  '())
              (if (not (empty-tree? (right-tree t)))
                  (list (root-tree (right-tree t)))
                  '()))))



(define t(make-tree 3
                    (make-tree 5
                               (make-tree 8
                                          (make-tree 10
                                                     empty-tree
                                                     empty-tree)
                                          empty-tree)
                               (make-tree 9
                                          (make-tree 13
                                                     empty-tree
                                                     (make-tree 7
                                                                empty-tree
                                                                empty-tree))
                                          empty-tree))
                    (make-tree 2
                               empty-tree
                               (make-tree 1
                                          empty-tree
                                          empty-tree))))
