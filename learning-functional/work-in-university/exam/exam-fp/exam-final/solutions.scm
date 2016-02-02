
;Task 2
(define (combine f g h) (lambda (x) (h (f x) (g x))))

;returns combinations of all functions
(define (descartes uns) ())

;generates numbers from a to b
(define (from-to a b)
  (if (= a b) (list b)
      (cons a (from-to (+ 1 a) b))))

;generates the values for a function in the interval a b
(define (generate-values f a b)
  (map f (from-to a b)))

;check if two lists are the ame
(define (are-same-size-lists-equal lst1 lst2)
 (if (null? lst1)
     #t
     (and ( = (car lst1) (car lst2)) (are-lists-equal (cdr lst1) (cdr lst2)))))

(gnerate values


; Task 3
(define G '((1 2 3)
            (2 3 6)
            (3 4 6)
            (4 1 5)
            (5 3)
            (6 5)
            (7)))

(define (vertices g) (map car g))
(define (children v g) (cdr (assq v g)))

(define (max-path u g)
  (define (helper g max-p current-path))
    (let ((v (car current-path)))
      (cond ((memq? v current-path) (if (> (length max-p)  (length current-path))
                                        max-p
                                        current-path
            (else (helper g (append current-path (children (current-v))))))))
