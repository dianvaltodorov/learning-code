;Зад.1. Да се напише функция (mash f g lst), която приема две
;едноаргументи функции и един списък и прилага f и g върху
;елементите на списъка, като ги редува:
(define (mash f g lst)
  (define (helper i l res)
    (cond ((null? l) res)
          ((= (remainder i 2) 1) (helper (+ i 1)
                                         (cdr l)
                                         (append res (list (f (car l))))))
          (else (helper (+ i 1) (cdr l) (append res (list (g (car l))))))))
  (helper 1 lst '()))

(define (f1 x) (* x 10))
(define f2 (lambda(i) (number? i)))
(mash f1 f2 '(1 2 3 4 5)) ;-> (10 #t 30 #f 50)

;Зад.2. Да се напише функция (insert-after-evens x lst), която вмъква числото x след всяко четно число в простия списък от числа lst:
(define (insert-after-evens x lst)
  (define (helper l res)
    (cond ((null? l) res)
          ((even? (car l)) (helper (cdr l) (append res (list (car l) x))))
          (else (helper (cdr l) (append res (list (car l)))))))
  (helper lst '()))

(insert-after-evens 10 '(1 2 3 4 5)) ;-> (1 2 10 3 4 10 5)

;Зад.3. Да се напише функция (insert-after-deep x lst), която вмъква
;числото x след всяко четно число в дълбокия списък от числа lst:
(define (atom? x)
  (and (not (pair? x))
       (not (null? x))))


(define (insert-after-deep l)
  (cond
    ((null? l) l)
    ((list? (car l)) (cons
                       (insert-after-deep (car l))
                       (insert-after-deep (cdr l))))
    ((even? (car l)) (cons (car l) (cons
                                  10
                                  (insert-after-deep (cdr l))) ))
    (else (cons (car l)
                (insert-after-deep (cdr l))))))


(insert-after-deep '(1 ((2) 3 4) (((5))) 6 7)) ;-> (1 ((2 10) 3 4 10) (((5))) 6 10 7)

;Зад.4. Да се напише функция (sublist? lst1 lst2), която проверява дали
;списъкът lst1 е подсписък на lst2 (аналогична на проверката за подстринг):

;Упътване: можете да използвате помощна функция (begins-with? lst1 lst2),
;която да проверява дали списъка lst2 "започва със" списъка lst1:
(define (begins-with? l1 l2)
  (cond
    ((null? l1) #t)
    ((null? l2) #f)
    ((not (= (car l1)(car l2))) #f)
    (else (begins-with? (cdr l1) (cdr l2)))))

(define (count-occurences-i l1 l2)
 (define (helper res l)
   (cond ((null? l) res)
         ((begins-with? l l2) (helper (+ res 1) (cdr l)))
         (else (helper res (cdr l)))))
  (helper 0 l1))

(define (count-occurences-rec l1 l2)
 (cond
   ((null? l1) 0)
   ((begins-with? l1 l2) (+ 1 (count-occurences-rec (cdr l1) l2)))
   (else (count-occurences-rec (cdr l1) l2))))

(define (sublist? l1 l2)
  (cond ((> (length l1) (length l2)) #f)
        ((begins-with? l1 l2) #t)
        (else (sublist? l1 (cdr l2)))))

(begins-with? '(2 3 4) '(2 3 4 5)) ;-> #t
(begins-with? '(2 3 4) '(2 3)) ;-> #f ;(!)

(sublist? '(2 3 4) '(1 2 3 4 5)) ;-> #t
(sublist? '(2 3 5) '(1 2 3 4 5)) ;-> #f ; тъй като търсените елементи не са последователни
(sublist? '(4 3 5) '(1 2 3 4 5)) ;-> #f
(sublist? '() '()) ;-> #t ;(!)

;Зад.5. Да се напише функция (make-set lst), която взима произволен списък (вида на елементите му няма значение) и връща списък от същите елементи, без повторения.
;Последователността на елементите в резултата няма значение, не се гони и сложност по време.
(define (has-item? x lst)
  (cond ((null? lst)  #f)
        ((equal? (car lst) x) #t)
        (else (has-item? x (cdr lst)))))

(define (make-set lst)
  (define (helper res l)
    (cond ((null? l) res)
          ((has-item? (car l) res) (helper res (cdr l)))
          (else (helper (cons (car l) res) (cdr l)))))
  (helper '() lst))

(make-set '(1 2 2 4 3 2 1 3 4)) ;-> (1 2 4 3)                               ; или друга тяхна пермутация
(make-set '("iei" 10 "oops" "iei" #t #t 10 #f)) ;-> ("iei" 10 "oops" #t #f) ; или друга тяхна пермутация

;Бонус: Да се напише функция (descartes lst1 lst2), която намира декартовото произведение на два списъка - наредените двойки от всеки елемент на единия списък със всеки елемент на другия.
;Последователността на елементите в резултата няма значение.
(define (descartes l1 l2)
  (apply append
         (map (lambda (item-from-first-list) (map (lambda (i) (cons item-from-first-list i))
                                                  l2))
              l1)))

(descartes '(1 2 3) '(a b)) ;-> ((1 . a) (2 . a) (3 . a)
                            ;   (1 . b) (2 . b) (3 . b)) ; или друга тяхна пермутация
