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

;(sum-negative-list '(1 2 -3 -4 5)) ; -> -7
