(define G '((1 (2 3))
            (2 (4))
            (3 (2))
            (4 (3 5))
            (5 (3 6))
            (6 ())))

(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

(define (vertices G) (map car G))
(vertices G) ;-> '(1 2 3 4 5 6)

(define (adjacent G v)
  (if(= (car (car G)) v)
    (car (cdr (car G)))
    (adjacent (cdr G) v)))

;(adjacent G 4) ;-> '(3 5)

(define (adjacent-f G v)
  (cadar (filter (lambda (row) (= (car row) v)) G)))

;(adjacent-f G 4) ;-> '(3 5)
(define (edges G)
  (apply append (map (lambda (row) (map (lambda (x) (cons (car row) x))
                                      (cadr row)))
                   G)))
(edges G) ;-> '((1.2) (1.3) (2.4).....)


(define (degree G v)
  (+ (length (adjacent G v))
     (length (filter (lambda(x) (= x v)) (apply append (map (lambda (row) (cadr row)) G))))))

(degree G 2)

(define (out G v)
  (length (adjacent G v)))

(define (in G v)
  (length (filter (lambda(x) (= x v)) (apply append (map (lambda (row) (cadr row)) G)))))

define (dfs-stack graph v)
(define (dfs-helper stack visited)
  (cond ((null? stack) '())
        ((member (top stack) visited) (dfs-helper (cdr stack) visited))
        (else (cons (top stack)
                    (dfs-helper (append (pop stack)
                                        (reverse (adjacent graph (top stack))))
                                (cons (top stack) visited))))))
(dfs-helper (list v) '()))

(define (bfs graph v)
  (define (dfs-helper queue visited)
    (cond ((null? queue) '())
          ((member (top stack) visited) (dfs-helper (cdr queue) visited))
          (else '())))))
