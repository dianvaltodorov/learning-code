(define (accumulate op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

;Зад.1. Да се напише функция (squares-product a b), която изчислява произведението на всички точни квадрати в даден целочислен интервал [a;b]. Hint: използвайте вградения предикат (integer? n).
;(squares-product 1 10) -> 36   ; =1*4*9 = 1^2+2^2+3^2
;(squares-product 1000 1100) -> 1115136   ; =1115136 = 10562
(define (squares-product a b)
  (accumulate *
              1
              (lambda (i) (if (integer? (sqrt i)) i 1))
              a
              (lambda (i) (+ i 1))
              b))

;Зад.2. Да се напише функция (sum-row x n), която изчислява сумата на първите n члена на реда x,x^2,x^4,x^8,x^16,...:
;(sum-row 2 6) -> 4295033110   ; = 2+2^2+2^4+2^8+2^16+2^32
;(sum-row 1/10 4) -> 11010001/100000000

(define (sum-row x n)
  (accumulate +
              0
              (lambda(i) (expt x (expt 2 i)))
              0
              (lambda (i) (+ i 1))
              (- n 1)))

;Зад.3. Да се напише функция (const? f a b), която проверява дали дадена функция е константна в даден целочислен интервал:
;(const? (lambda (x) 5) 1 100) -> #t
;(const? (lambda (x) (+ x 1)) 1 3) -> #f
;(const? fact 0 1) -> #t

;(define example-polynomial (lambda (x) (+ (expt x 4) (* -10 (expt x 3)) (* 35 (expt x 2)) (* -50 x) 24)))
; example-polynomial си е полином, т.е. функцията x4-10x3+35x2-50x+24
;(const? example-polynomial 1 4) -> #t

(define example-polynomial (lambda (x) (+ (expt x 4) (* -10 (expt x 3)) (* 35 (expt x 2)) (* -50 x) 24)))

(define (const? f a b)
  (= 1 (accumulate *
                   1
                   (lambda(i) (if(= (f a) (f i)) 1 0))
                   a
                   (lambda (i) (+ i 1))
                   b)))

;Бонус: Да се напише функция (max-fun f a b), която намира максимума на дадена функция в целочисления интервал [a;b]. Hint: в
;Scheme съществуват -inf.0 и +inf.0 като валидни и "точни" стойности за безкрайностите - използвайте ги при нужда.
;(max-fun (lambda (x) (* x 2)) 10 20) -> 40.0
;(max-fun example-polynomial -2 5) -> 360.0

(define (max-fun1 f a b)
  (define (is-max? cur)
    (= 1 (accumulate max
                     1
                     (lambda(i) (if(>= (f cur) (f i)) 1 0))
                     a
                     (lambda (i) (+ i 1))
                     b)))
  (define (helper i)
    (cond ((> i b) (f b))
          ((is-max? i) (f i))
          (else (helper (+ i 1)))))
  (helper a))

(define (max-fun2 f a b)
  (accumulate (lambda (res new-val) (if(> res new-val) res new-val))
             -inf.0
             (lambda(i) (f i))
             a
             (lambda (i) (+ i 1))
             b))


(define (max-fun f a b)
 (accumulate (lambda (res new-val) (max res new-val))
            -inf.0
            (lambda(i) (f i))
            a
            (lambda (i) (+ i 1))
            b))
