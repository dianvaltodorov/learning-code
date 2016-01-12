(define (accumulate-rec op null-value term a next b)
  (if(> a b)
     null-value
     (op (term a) (accumulate op null-value term (next a) next b))))

(define (accumulate-i op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

(define (filter-accum-rec pred? op null-value term a next b)
  (cond ((> a b) null-value)
        ((pred? a) (op (term a)
                       (filter-accum-rec pred?
                                         op
                                         null-value
                                         term
                                         a
                                         next
                                         b)))
        (else (filter-accum-rec pred?
                                op
                                null-value
                                term
                                a
                                next
                                b))))

(define (filter-accum-i pred? op null-value term a next b)
  (define (helper i res)
     (cond ((> i b) res)
           ((pred? i) (helper (next i) (op res (term i))))
           (else (helper (next i) res))))
  (helper a null-value))

;Зад.1. Да се напише функция (fact-accum n), която изчислява факториела на дадено естествено число.
(define (fact-accum n)
  (accumulate-i *
                1
                (lambda (x) x)
                1
                (lambda (x) (+ x 1))
                n))

;Зад.2. Да се напише функция (expt-accum x n), която повдига числото x на степен n (n - естествено число).
(define (expt-accum x n)
  (accumulate-i *
                1
                (lambda (i) x)
                1
                (lambda (x) (+ x 1))
                n))
;Зад.3. Да се напише функция (count-divisors n a b), която намира броя на делителите на естественото число n в интервала [a;b].
(define (count-divisors n a b)
  (accumulate-i +
                0
                (lambda (i) (if(= 0 (remainder n i)) 1 0))
                a
                (lambda (i) (+ i 1))
                b))
;Зад.4. Да се напише функция (count-fixed f a b), която намира броя на неподвижните функции на функцията f в интервала [a;b].
(define (count-fixed f a b)
  (accumulate-i +
                0
                (lambda (i) (if(= i (f i)) 1 (0)))
                a
                (lambda (i) (+ i 1))
                b))

;Зад.5. Да се напише функция (powers-sum x n), която намира сумата x + 2x2 + 3x3 + ... + nxn за дадени числа x и n (n - естествено число).
(define (powers-sum x n)
  (accumulate-i +
                0
                (lambda (i) (expt x i))
                1
                (lambda (i) (+ i 1))
                n))
;Зад.6. Да се напише функция (func-sum f n), която намира сумата f(0) + f(1) + ... f(n) за дадена функция f и естествено число n.
(define (func-sum f n)
  (accumulate-i +
                0
                f
                1
                (lambda (i) (+ i 1))
                n))

;Зад.6. Да се напише функция (combinations n k), която за дадени естествени числа n и k изчислява биномния коефициент (n k).
(define (combinations n k)
  (/ (accumulate-i *
                   1
                   (lambda (x) x)
                   1
                   (lambda (x) (+ x 1))
                   n)
       (* (accumulate-i *
                     1
                     (lambda (x) x)
                     1
                     (lambda (x) (+ x 1))
                     k)
          (accumulate-i *
                     1
                     (lambda (x) x)
                     1
                     (lambda (x) (+ x 1))
                     (- n k)))))



;Зад.7. Да се напише функция (prime-accum n), която проверява дали едно число е просто.
(define (prime-accum? n)
 (= 0 (accumulate-i +
                        0
                        (lambda (i) (if (= 0 (remainder n i)) 1 0))
                        2
                        (lambda (i) (+ i 1))
                        (sqrt n))))

;Зад.8. Да се напиша функция (perfect-accum n), която проверява дали едно число е съвършено.
(define (perfect-accum n)
  (= n (accumulate-i *
                     1
                     (lambda (i) (if(= 0 (remainder n i)) i 0))
                     1
                     (lambda (i) (+ i 1))
                     (/ n 2))))

;зад.9. Да се напише функция (integrate f a b dx), която изчислява определения интеграл на функцията f в интервала [a;b] с точност dx.
(define (integrate f a b dx)
  (= n (accumulate-i +
                     0
                     (lambda(i) (* dx (f x)))
                     a
                     (lambda (i) (+ i dx))
                     b)))

;зад.10 Sum divisors
(define (sum-divisors n)
  (accumulate-i +
                0
                (lambda (i) (if(= 0 (remainder n i)) i 0))
                1
                (lambda (i) (+ i 1))
                (/ n 2)))
