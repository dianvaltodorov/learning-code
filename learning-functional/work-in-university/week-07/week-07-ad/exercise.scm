(define
  term acuumulate(*
                  (lambda (i) ((average f (lambda (x) (expt i x)))))
                  l
                  ++
                  n)


(map (lambda (x y) (+ x y)) '(1 2 3 4) '(7 8 9 10))


(define (match? l1 l2)
  (let* ((d1 (map length l1))
        (d2 (map length l2))
        (len-diffs (map (lambda x y) ((abs ) (- x y)))))
        (null? (filter (lambda (el) (not equal? el (car (len-diffs))))))))


(foldr (lambda (x y) (and x y) (map (lambda (el) (equal? el (car len-diffs)) )))) len-diffs)
