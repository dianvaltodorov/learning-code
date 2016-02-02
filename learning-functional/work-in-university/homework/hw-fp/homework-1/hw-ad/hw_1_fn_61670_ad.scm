;Зад.1. Да се напише функция (GCD a b), която намира най-големия общ делител на две естествени числа по метода на Евклид:
;
;function gcd(a, b)
;    while a ≠ b
;        if a > b
;           a := a − b
;        else
;           b := b − a
;    return a

(define (GCD-yo x y)
  (define (helper a b)
    (cond ((= a b) a)
          ((> a b) (helper (- a b) b))
          ((< a b) (helper a (- b a)))))
  (helper x y))

;Зад.2. Да се напише функция (LCM a b), която намира най-малкото общо кратно на две естествени числа.
(define (LCM-yo x y)
  (/ (* x y) (my-GCD-yo x y)))


(define (count-digits n)
  (define (helper n result)
    (if(<= n 9)
       (+ 1 result)
       (helper (quotient n 10) (+ result 1))))
  (helper n 0))

;Зад.3. Да се напише функция (ends-with? a b), която проверява дали числото а "завършва" на b:
;(ends-with? 1234 34) -> #t
;(ends-with? 56789 189) -> #f
(define (ends-with? a b)
   (= b (remainder a (expt 10 (count-digits b)))))


;Зад.4. Да се напише функция (substr? a b), която проверява дали числото b се съдържа в a като подстринг:
;(substr? 12345 234) -> #t
;(substr? 12345 423) -> #f
(define (substr? a b)
  (define (helper current)
    (cond
      ((< current (expt 10 (count-digits b))) #f)
      ((ends-with? current b) #t)
      (else (helper(quotient current 10)))))
  (helper a))

;Зад.5. Да се напише функция (occurrences a n), която намира колко пъти цифрата a се среща в записа на естественото число n:
;(occurrences 3 123123) -> 2
;(occurrences 5 123123) -> 0
(define (occurrences a n)
  (define (helper n res)
    (cond
      ((= n 0) res)
      ((= a (remainder n 10)) (helper (quotient n 10) (+ 1 res)))
      (else (helper (quotient n 10)  res))))
  (helper n 0))


;Зад.6. Да се напише функция (contains-digits? a b), която проверява дали всички цифри на числото b се съдържат в числото a:
;(contains-digits? 12345 423) -> #t        ;забележете разликата с функцията substr?
;(contains-digits? 123123123123 4) -> #f
;(contains-digits? 10 1010001001010101) -> #t
(define (contains-digits? a b)
  (define (has-digit? a digit)
    (define (helper current)
      (cond
        ((= current 0) #f)
        ((= digit (remainder current 10)) #t)
        (else (helper (quotient current 10)))))
    (helper a))
  (define (helper current)
    (cond
      ((= current 0 ) #t)
      ((has-digit? a (remainder current 10)) (helper (quotient current 10)))
      (else #f)))
  (helper b))

;Зад.7. (Бонус) Да се напише функция (toBinary n), която превръща дадено естествено число в двоична бройна система:
;(toBinary 8) -> 1000
;(toBinary 15) -> 1111
;(toBinary 42) -> 101010

(define (toBinary n)
  (define (special-reversed n)
    (define (helper current res)
      (if(= current 0)
         res
         (helper (quotient current 10) (+ (* res 10)(-(remainder current 10) 1)))))
    (helper n 0))
  (define (helper current result)
    (if(= current 0)
      (special-reversed result)
      (helper (quotient current 2) (+ (* result  10) (+ 1 (remainder current 2))))))
  (helper n 0))
