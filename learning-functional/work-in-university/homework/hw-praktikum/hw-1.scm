;Задача 1. Използвайки фунцкиите от по-висок ред map, filter и accumulate,
;имплементирайте фунцкия, която по даден списък от цели числа, намира сумата
;от тези числа в списъка, които дават остатък 2 при делене на 3, като
;положителните числа се взимат с обратен знак.
(define (filter p? l)
  (cond ((null? l)'())
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

(define (accumulate op nv l)
  (if (null? l) nv
      (op (car l) (accumulate op nv (cdr l)))))


(define (sum-negative-list l)
  (accumulate +
              0
              (map (lambda (x) (if (> x 0) (- x) x))
                (filter (lambda(x) (= (remainder x 3) 2))
                l))))

(sum-negative-list '(1 2 -3 -4 5)) ; -> -7

;Задача 2. Нека имаме представяне на група студенти чрез списък от списъци
;от вида: '(<faculty_number> <name> <grade>). Да се имплементират следните функции:
;функция, която изчислява средния успех на групата студенти функция която връща
;списък от факултетните номера на студентите, които имат по-висок от средния успех.
;За имплементацията изпозлвайте функциите от по-висок ред map, filter и accumulate.

(define (filter p? l)
  (cond ((null? l)'())
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

(define (accumulate op nv l)
  (if (null? l) nv
      (op (car l) (accumulate op nv (cdr l)))))


(define class '((77777 "Ivan" 5) (88888 "Stoyan" 3) (99999 "Penka" 6)))

(define (average class)
  (/ (accumulate +
                 0
                 (map (lambda (student) (caddr student)) class)) (length class)))

(average class) ;-> 4 2/3

(define (higher-than-average class)
   (map car (filter (lambda (x) (> (caddr x) (average class))) class)))

(higher-than-average class) ;->(77777 99999)

;Задача 3. Да се напише функция remove-element elem lst, която приема като
;аргументи елемент и списък и връща като резултат нов списък, с премахнати
;всички срещания на елементът от списъка.

(define (remove-element x l)
  (filter (lambda (el) (not (equal? x el))) l))

(remove-element "hi" '("hello" "hi" "world" "hi")) ; -> ("hello" "world")
(remove-element 1 '()) ; -> ()
(remove-element '() '(() (()) (1 2 3))) ; -> ((()) (1 2 3))

;Задача 4. Да се имплементира фунцкията histogram lst, която съставя хистограма
;от срещанията на елемент в списък. Резултатът от функцията трябва да е списък
;от точкови двойки като първият елемент на двойката е самият елемент, а вторият
;- броят на срещанията на елемента в списъка.

(define (count-occurences x l)
  (define (helper res lst)
    (cond ((null? lst) res)
          ((equal? (car lst) x) (helper (+ 1 res) (cdr lst)))
          (else (helper res (cdr lst)))))
  (helper 0 l))

(define (has-pair? x lst)
  (cond ((null? lst)  #f)
        ((equal? (car (car lst)) (car x)) #t)
        (else (has-pair? x (cdr lst)))))

(define (make-set lst)
  (define (helper res l)
    (cond ((null? l) res)
          ((has-pair? (car l) res) (helper res (cdr l)))
          (else (helper (append res (list (car l)) ) (cdr l)))))
  (helper '() lst))

(define (histogram lst)
  (make-set (map (lambda (x) (cons x (count-occurences x lst))) lst)))

(histogram '()) ; -> ()
(histogram '(4 8 2 3 3 4 5 6 4)) ; -> ((4 . 3) (8 . 1) (2 . 1) (3 . 2) (5 . 1) (6 . 1))
(histogram '(#\a #\b #\c #\d #\b #\e #\b)) ; -> ((#\a . 1) (#\b . 3) (#\c . 1) (#\d . 1) (#\e . 1))

;Задача 5. Да се имплементира фунцкията merge-sorted l1 l2 pred?, която слива
;два предварително сортирани списъка в нов списък, също сортиран, според предиката pred?
(define (merge-sorted l1 l2 pred?)
  (cond ((or (null? l1) (null? l2)) (append l1 l2))
        ((pred? (car l1) (car l2)) (append (list (car l1)) (merge-sorted (cdr l1) l2 pred?)))
        (else (append (list (car l2)) (merge-sorted l1 (cdr l2) pred?)))))

(merge-sorted '(1 3 5 7) '(2 4 6) <) ; -> (1 2 3 4 5 6 7)
;Задача 6. Имплементирайте алгоритъма за сортиране чрез сливане. Функцията трябва да приема списък и предикат, а резултатът трябва да е нов списък, който е сортиран спрямо предиката.
;
;Пример:
;(merge-sort '(3 1 -2 5) <)
;(-2 1 3 5)

(define (list-head lst n)
  (cond ((= n 0) '())
        (else (cons (car lst) (list-head (cdr lst) (- n 1))))))

(define (merge-sorted l1 l2 pred?)
  (cond ((or (null? l1) (null? l2)) (append l1 l2))
        ((pred? (car l1) (car l2)) (append (list (car l1)) (merge-sorted (cdr l1) l2 pred?)))
        (else (append (list (car l2)) (merge-sorted l1 (cdr l2) pred?)))))

(define (merge-sort l pred?)
  (cond ((null? l)  '())
        ((= 1 (length l)) l)
        ((= 2 (length L)) (merge-sorted (list (car L)) (cdr L) pred?))
        (else (merge-sorted (merge-sort (list-head l (quotient (length l) 2)) pred?)
                            (merge-sort (list-tail l (quotient (length l) 2)) pred?)
                            pred?))))
