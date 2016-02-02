(define G '((1 2 3)
            (2 3 6)
            (3 4 6)
            (4 1 5)
            (5 3)
            (6 5)
            (7)))

(define (foldr op nv l)
    (if (null? l)
        nv
        (op (car l) (foldr op nv (cdr l)))))


(define (vertices g) (map car g))

(define (children v g) (cdr (assq v g)))

(define (edge? u v g) (memq v (children u g)))

(define (map-children v f g) (map f (children v g)))

(define (search p l)
  (and (not (null? l))
       (or (p (car l)) (search p (cdr l)))))

(define (search-children v f g) (search f (children v g)))

(define (filter p? l)
  (foldr (lambda (h t) (if (p? h) (cons h t) t)) '() l))

(define (childless g)
  (filter (lambda (v) (null? (children v g))) (vertices g)))

(define (parents v g)
  (filter (lambda (u) (edge? u v g)) (vertices g)))

(define (forall p? l)
  ; #t <-> за всеки елемент в l е вярно p?
  (not (search (lambda (x) (not (p? x))) l)))

(define (symmetric? g)
  (forall (lambda (v)
             (forall (lambda (u) (edge? u v g))
                     (children v g)))
          (vertices g)))

(define (cons#f h t) (and t (cons h t)))

(define (dfs-path u v g)
  (or (and (eq? u v) (list u))
      (cons#f u (search-children u (lambda (c) (dfs-path c v g)) g))))

(define (dfs-path u v g)
  (define (dfs-path-search path)
    (let ((current (car path)))
    (cond ((eq? current v) (reverse path))
          ((memq current (cdr path)) #f) ; избягваме зациклянето
          (else (search-children current
                                 (lambda (c) (dfs-path-search (cons c path)))
                                 g)))))
  (dfs-path-search (list u)))

(define (bfs-path u v g)

(define (extend path)
  (map-children (car path) (lambda (c) (cons c path)) g))

(define (extend-acyclic path)
  (define (acyclic? path)
    (not (memq (car path) (cdr path))))
  (filter acyclic? (extend path)))

(define (extend-level l)
  (apply append (map extend-acyclic l)))

(define (bfs-level l)
  (and (not (null? l))
       (or (search (lambda (path) (and (eq? (car path) v) path)) l)
           (bfs-level (extend-level l)))))

(bfs-level (list (list u))))
