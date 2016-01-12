(define n0 (lambda() 'null))
(define (inc x)
  (lambda () x))
(define (dec x)
  (x))

(define n1 (inc n0))
(define n2 (inc n1))
(define n3 (inc n2))
(define n4 (inc n3))
(define n5 (inc n4))
(define n6 (inc n5))

(define (isZero? n)
  (eq? (n) 'null))

(define (isEqual? x y)
  (cond
    ((isZero? x) (isZero? y))
    ((isZero? y) (isZero? x))
    (else (isEqual?
           (dec x)
           (dec y)))))

(define (plus x y)
 (if (isZero? y)
     x
     (plus(inc x) (dec y))))

(isZero? n0)

(isEqual? (plus n3 n2) n5)

(isEqual?
 (plus (plus n3 n2) n5)
 (plus (plus n4 n2) n4))
