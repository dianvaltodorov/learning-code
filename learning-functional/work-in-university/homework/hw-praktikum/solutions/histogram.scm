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

;(histogram '()) ; -> ()
;(histogram '(4 8 2 3 3 4 5 6 4)) ; -> ((4 . 3) (8 . 1) (2 . 1) (3 . 2) (5 . 1) (6 . 1))
;(histogram '(#\a #\b #\c #\d #\b #\e #\b)) ; -> ((#\a . 1) (#\b . 3) (#\c . 1) (#\d . 1) (#\e . 1))
