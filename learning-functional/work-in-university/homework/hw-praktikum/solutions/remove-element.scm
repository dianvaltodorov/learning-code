;Задача 3. Да се напише функция remove-element elem lst, която приема като
;аргументи елемент и списък и връща като резултат нов списък, с премахнати
;всички срещания на елементът от списъка.

(define (remove-element x l)
  (filter (lambda (el) (not (equal? x el))) l))

;(remove-element "hi" '("hello" "hi" "world" "hi")) ; -> ("hello" "world")
;(remove-element 1 '()) ; -> ()
;(remove-element '() '(() (()) (1 2 3))) ; -> ((()) (1 2 3))
