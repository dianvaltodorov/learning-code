;Задача 1. Да се напише функция (min-sum-digit a b k), която намира
;най-малкото от целите числа от a да b, чиято сума на цифрите се дели на k.

;Примаме, че със сигурност има число, чиято сума от цифрите се дели k в интервала
(define (min-sum-digit a b k)
  (define (sum-digits n)
    (define (sum-digits-helper n res)
      (if(= 0 n)
         res
         (sum-digits-helper (quotient n 10)
                 (+ res (remainder n 10)))))
    (sum-digits-helper n 0))
  (define (helper i)
      (if (= (remainder (sum-digits i) k) 0)
          i
          (helper (+ i 1))))
  (helper a))

(min-sum-digit 10 20 3) ; -> 12
(min-sum-digit 10 20 7) ; -> 16
(min-sum-digit 20 40 3) ; -> 21
(min-sum-digit 110 200 8) ; -> 116
(min-sum-digit 200 300 15) ; ->  249

;Задача 2. Да се напише функция (average f g), която по две числови функции
;f : R → R и g : R → R  намира средно-аритметичната функция (f⊕g)(x)=f(x)+g(x)2.
;С помощта на average да се напише функция от по-висок ред (calcprod f n), която
;намира произведението ∏ni=1(f⊕gi)(i), където gi(x) = i^x. Използването на
;accumulate е позволено, но не е задължително.

(define (accumulate op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

(define (average f g)
  (lambda (x) (/ (+ (f x) (g x)) 2)))


(define (calcprod f n)
    (define (gi x) (expt x x))
    (accumulate *
                1
                (lambda (i) ((average f gi) i))
                1
                (lambda (i) (+ i 1))
                n))

;Задача 3. Да се дефинира функция (occurrences l1 l2). l1 и l2 са списъци от
;числа. Функцията да конструира списък с броя на срещанията на всеки от
;елементите на l1 в l2.
(define (count-occurrences-rec x l)
  (cond ((null? l) 0)
        ((= x (car l) x) (+ 1 (count-occurrences x (cdr l))))
        (else (count-occurrences x (cdr l)))))

(define (count-occurrences-it x l)
  (define (helper res l)
    (cond((null? l) res)
         ((= x (car l) x) (helper (+ res 1) (cdr l)))
         (else (helper res (cdr l)))))
  (helper 0 l))


(define (count x lst)
  (length (filter (lambda (el) (equal? x el)))) lst)

(define (length lst)
  (apply + (map (lambda (el) 1) lst))

(define (occurrences-my l1 l2)
  (define (count-occurrences-it x l)
    (define (helper res l)
      (cond((null? l) res)
           ((= x (car l) x) (helper (+ res 1) (cdr l)))
           (else (helper res (cdr l)))))
    (helper 0 l))
  (define (helper res l)
    (if(null? l)
        res
        (helper (append res (list (count-occurrences-it (car l) l2)))
                (cdr l))))
  (helper '() l1))

(define (occurrences l1 l2)
  (define worker (lambda (element) (count element l2)))
  (map worker l1)

(occurrences '(1 2 3) '( 1 2 4 1 )); -> (2 1 0)


;Задача 4. Да се дефинира предикат (match-lenghts? l1 l2). l1 и l2 са непразни
;списъци от списъци от числа. Ако l1 = (a1 a2 … ak), а l2 = (b1 b2 … bk) ,
;предикатът да връща истина, когато разликите в дължините на всяка двойка
;съответни списъци ai и bi е еднаква.
(define (match-lengths? l1 l2)
  (define (helper len l1 l2)
      (cond ((null? l1) #t)
            ((= len (- (length (car l1)) (length (car l2)))) (helper len (cdr l1) (cdr l2)))
            (else #f)))
  (helper (- (length (car l1))  (length (car l2))) (cdr l1) (cdr l2)))

(match-lengths? '( () (1 2) (3 4 5)) '( (1) (2 3 4) (5 6 7 9))); -> #t,
(match-lengths? '( () (1 2) (3 4 5)) '( () (2 3 4) (5 6 7))); -> #f
(match-lengths? '( () (1 2) (3 4 5)) '( () (2 3 4) (5 6 7))); -> #f
