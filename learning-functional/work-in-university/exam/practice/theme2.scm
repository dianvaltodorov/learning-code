(define (accumulate op null-value term a next b)
  (define (helper i res)
    (if(> i b)
       res
      (helper (next i) (op res (term i)))))
  (helper a null-value))

;Задача 1. Да се напише функция (prod-sum-div a b k), която намира
;произведението на всички цели числа от a да b, които имат сума на делителите
;кратна на k.
(define (sum-divisors x)
    (accumulate +
                x
                (lambda (i) (if (= (remainder x i) 0)
                                i
                                0))
                1
                (lambda (i) (+ i 1))
                (/ x 2)))

(define (prod-sum-div a b k)
  (accumulate *
              1
              (lambda (i) (if (= (remainder (sum-divisors i) k) 0)
                              i
                              1))
              a
              (lambda (i) (+ i 1))
              b))

(prod-sum-div 1 6 2) ; -> 90

;Задача 2. Да се напише функция (average f g), която по две числови функции
;f : R → R и g : R → R намира средно-геометричната функция (f⊗g)(x)=f(x)g(x).
;С помощта на average да се напише функция от по-висок ред (calcsum f n), която
;намира сумата ∑ni=1(f⊗gi)(i), където gi(x) = xi. Използването на accumulate
;е позволено, но не е задължително.
(define (average-geo f g)   (lambda (x) (sqrt ( * (f x) (g x)))))

(define (calcsum-geo f n)
    (define (gi x) (expt x x))
    (accumulate +
                0
                (lambda (i) ((average-geo f gi) i))
                1
                (lambda (i) (+ i 1))
                n))

;((calcsum-geo (lambda(i) i) 4) 1) ;-> 10
;Задача 3. (1.25 т.) Да се дефинира функция (duplicates l1 l2). l1 и l2 са
;списъци от числа. Функцията построява списъка от тези числа в l1, които се
;срещат повече от веднъж в l2. ;Пример: (duplicates ‘(1 2 3) ‘(1 2 1 3 2)) -> (1 2)
(define  (duplicates l1 l2)
  (define (occurs-more-than-once? x l)
    (define (helper times l)
      (cond ((> times 1) #t)
            ((null? l) #f)
            ((= x (car l)) (helper (+ times 1) (cdr l)))
            (else (helper times (cdr l)))))
    (helper 0 l))
  (define (helper res l)
    (cond ((null? l) res)
          ((occurs-more-than-once? (car l) l2) (helper (append res (list (car l))) (cdr l)))
          (else (helper res (cdr l)))))
  (helper '() l1))

  (define (count x lst)
    (length (filter (lambda (el) (equal? x el)))) lst)

  (define (length lst)
    (apply + (map (lambda (el) 1) lst))

  (define (duplicates l1 l2)
    (define  worker (lambda (el) (> (count el l2) 1))))
    (filter worker l1)
    
;Задача 4. (1.25 т.) Да се дефинира предикат (image? l1 l2). l1 и l2 са непразни
;списъци с еднакъв брой числа.Ако l1 = (a1 a2 … ak), а l2 = (b1 b2 … bk),
;предикатът да връща истина, когатосъществува такова число x,
;че ai = x + bi ,за всяко i = 1...k.

(define (image? l1 l2)
  (define (helper x l1 l2)
    (cond ((null? l1) #t)
          ((= x (- (car l1) (car l2))) (helper x (cdr l1) (cdr l2)))
          (else #f)))
  (helper (- (car l1) (car l2)) (cdr l1) (cdr l2)))

(image? '(1 2 3) '(4 5 6)) ;-> #t
(image? '(1 2 3) '(1 2 2 )) ;-> #f

(define (image-with-map? l1 l2)
   (equal? (map (lambda(i) (+ i (- (car l2) (car l1)))) l1) l2))

(image-map? '(1 2 3) '(4 5 6)) ;-> #t
(image-map? '(1 2 3) '(1 2 2 )) ;-> #f
