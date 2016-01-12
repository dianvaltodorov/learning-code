(define (hello-world)
  (display "Hello world"))

(define x 3)

(define (smaller x y)
  (if (> x y)
      y
      x))

(define (bigger x y)
  (if (> x y )
      x
      y))

(define(is-even x)
  (= (remainder x 2) 0))

(define(is-even2 x)
  (not (is-odd x)))

(define (is-odd x)
  (=(remainder x 2) 1))

(define (is-odd2 x)
  (not (is-even x)))

;1.14. define the predicate (is-positive? x) which tells if x is even; define a predicate (is-positive2? x) by negating whether x is negative
(define (is-positive x)
  (> x 0))

(define (is-positive2 x)
  (not (is-negative x)))

;1.15. define the predicate (is-negative? x) which tells if x is even; define a predicate (is-negative2? x) by negating whether x is positive
(define (is-negative x)
  (< x 0))

(define(is-negative2 x)
  (not (is-positive x)))

(define (sign x)
  (cond
    ((> x 0) 1)
    ((= x 0) 0)
    (else(< x 0) -1)))

(define (is-between-2-and-6)
  (and (> x 2) (< x 6)))

(define (modulus x)
  (if
    (> x 0)
    x
    (* -1 x)))

(define (modulus2 x)
  (cond
    ((> x 0) x)
    ((= x 0) x)
    ((< x 0) (* -1 x))))

(define(sum x y)
  (if
    (= x y)
    x
    (x + (sum (+ 1 x) y))
  ))

(define (multiply-sequence x y)
  (if
    (= x y)
    x
    (* x (multiply-sequence (+ x 1) y))))

(define (factorial x)
  (if(= x 2)
     x
     (* x (factorial (- x 1)))))

(define (pow x n)
  (if(= n 1)
     x
     (* x (pow x (- n 1)))))

(define (product-digits n)
 (if
   (< n 10)
   n
   (* (remainder n 10) (product-digits (quotient n 10)))))

(define (circle? circle-x circle-y radius point-x point-y)
  (< (distance circle-x circle-y point-x point-y) (square radius)))

(define (distance a-x a-y b-x b-y)
  (+ (square(- a-x b-x)) (square(- a-y b-y))))

(define (area a b c)
  (sqrt (* (semi-perimeter a b c) (- (semi-perimeter a b c) a)(- (semi-perimeter a b c) b)(- (semi-perimeter a b c) c))))

(define (semi-perimeter a b c)
  (/ (+ a b c) 2))

(define (quadrant x y)
  (cond
    ((and (> x 0) (> y 0)) 1)
    ((and (> x 0) (< y 0)) 2)
    ((and (< x 0) (< y 0)) 3)
    ((and (< x 0) (> y 0)) 4)))

(define (triangle? a b c)
  (and
    (> (+ a b) c)
    (> (+ b c) a)
    (> (+ c a) b)
    ))

(define (side-effects-square x)
  (display (* x x))
  (newline)
  (* x x))

(define (traffic-light color)
  (cond
    ((eq? "red") display "stop" )
    ((eq? "yellow") display "attention" )
    ((eq? "green") display "go" )
    (else display "sorry no idea")
  ))
