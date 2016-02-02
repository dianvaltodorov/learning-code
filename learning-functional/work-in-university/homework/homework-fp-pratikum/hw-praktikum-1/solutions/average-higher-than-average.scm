
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

;(average class) ;-> 4 2/3

(define (higher-than-average class)
   (map car (filter (lambda (x) (> (caddr x) (average class))) class)))

;(higher-than-average class) ;->(77777 99999)
