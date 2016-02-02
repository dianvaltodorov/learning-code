;Задача 6. Имплементирайте алгоритъма за сортиране чрез сливане. Функцията трябва да приема списък и предикат, а резултатът трябва да е нов списък, който е сортиран спрямо предиката.
;
;Пример:
;(merge-sort '(3 1 -2 5) <)
;(-2 1 3 5)

(define (merge-sorted l1 l2 pred?)
  (cond ((or (null? l1) (null? l2)) (append l1 l2))
        ((pred? (car l1) (car l2)) (append (list (car l1)) (merge-sorted (cdr l1) l2 pred?)))
        (else (append (list (car l2)) (merge-sorted l1 (cdr l2) pred?)))))

;(merge-sorted '(1 3 5 7) '(2 4 6) <) ; -> (1 2 3 4 5 6 7)
