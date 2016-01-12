(define-syntax cons-stream
  (syntax-rules ()
    ((cons-stream h t) (cons h (delay t)))))
(define (head str) (car str))
(define (tail str) (force (cdr str)))
(define (take n str)
  (if  (= n 0)
       '()
       (cons (head str)
             (take (- n 1) (tail str)))))

(define (integers-starting-from n)
  (cons-stream n (integers-starting-from (+ n 1))))
(define integers (integers-starting-from 1))

(define nats (cons-stream
              1
              (add-streams ones nats)))

(define ones (cons-stream 1 ones))
(define twos (cons-stream 2 twos))

(define (fib-gen a b)
  (cons-stream a (fib-gen b (+ a b))))
(define fibs1 (fib-gen 0 1))

(define fibs2 (cons-stream  0
                   (cons-stream 1
                                (add-streams fibs2 (tail fibs2)))))


;Predefined streams:

;Зад.0 Проба на tail и head cons-stream
;(define x (cons-stream 1 (cons-stream 2 (cons-stream 3 4))))
;(tail x)
;(tail (tail x))
;(tail (tail (tail x)))

; (tail (tail (tail (tail x)))) => Error

;Зад.1. Да се напише функция (add-streams str1 str2), която събира почленно два потока.
;(add-streams [1 2 3 ... ] [1 2 3 ... ]) -> [2 4 6 ...]
(define (add-streams str1 str2)
  (cons-stream (+ (head str1)
                   (head str2))
                (add-streams (tail str1)
                            (tail str2))))
;(take 10 (add-streams ones twos))

;Зад.2. Да се напише функция (map-stream f str), която прилага функцията f над
;потока str и връща поток от резултатите.
;(map (lambda (x) (* x x)) [1 2 3 ...]) -> [1 4 9 ...]
(define (map-stream f str)
  (cons-stream (f (head str))
               (map-stream f (tail str))))
;(take 10 (map-stream (lambda(x) (* x x)) twos))

;Зад.3. Да се напише функция (take n str), която връща списък от първите n елемента на потока str.
(define (take n str);
  (if  (= n 0)
       '()
       (cons (head str)
             (take (- n 1) (tail str)))))
;(take 10 fibs) ;-> (0 1 1 2 3 5 8 13 21 34)

; Зад.4. Да се генерира потокът triangs от всички триъгълни числа. Казваме,
; че n-тото триъгълно число T(n) = 1 + 2 + ... + n.
(define triangs1 (map-stream (lambda(x) (/ (* x (+ x 1)) 2)) integers))

(define (triangs-from i)
  (cons-stream ((lambda(x) (/ (* x (+ x 1)) 2)) i)
               (triangs-from (+ i 1))))
(define triangs3 (triangs-from 1))

(define (triangs-gen i prev)
  (cons-stream (+ prev i)
               (triangs-gen (+ i 1) (+ prev i))))
(define triangs2 (triangs-gen 1 0))

(take 5 triangs1) ;-> (1 3 6 10 15)  ;(Т(1) Т(2) Т(3) Т(4) Т(5))
(take 5 triangs2) ;-> (1 3 6 10 15)  ;(Т(1) Т(2) Т(3) Т(4) Т(5))
(take 5 triangs3) ;-> (1 3 6 10 15)  ;(Т(1) Т(2) Т(3) Т(4) Т(5))


;Зад.5. Да се напише функция (cycle lst), която получава списък от вида () и
;връща потока [a1, a2, a3, ..., an, a1, a2, ... ]
;(cycle '(1 2 3 4)) -> [1 2 3 4 1 2 3 4 1 2 3 4 ... ]

;1 начин
(define (cycle1 lst)
  (define (helper l)
    (if (null? l)
        (helper lst)
        (cons-stream (car l)
                     (helper (cdr l)))))
  (helper lst))

(take 10 (cycle1 '(1 2 3 4)))

;2 начин
(define (rotated l)
  (append(cdr l)
         (list (car l))))

(define (cycle2 lst)
  (cons-stream (car lst)
               (cycle2 (rotated lst))))
(take 10 (cycle2 '(1 2 3 4)))

;Задача 6. (double-cycle l)

(define (flip l)
  (append l
          (cdr (reverse (cdr l)))))

(define (double-cycle l)
  (cycle1 (flip l)))

(take 10 (cycle2 '(1 2 3 4)))

;Задача 7. Да се напише функция (sin-stream x), която връща поток от членовето на реда на Тейлър
(define (factorial n)
  (if(= n 0)
     1
  (* n (factorial (- n 1 )))))

(define (sin-stream-gen i x)
    (cons-stream (* (expt -1 i) (/ (expt x (+ (* 2 i) 1)) (factorial (+ (* 2 i) 1))))
               (sin-stream-gen (+ i 1) x)))

(define (sin-stream1 x) (sin-stream-gen 0 x))
(take 10 (sin-stream1 1))


(exact->inexact (apply + (take 10 (sin-stream1 1))))
(sin 1)

;x - x^3 / 3! + x^5 / 5! - x^7/7!
;Зад.8. Да се напише функция (compose-stream f), която връща потока от функции
;[id, f, f.f, f.f.f, ... ], където id е функцията-идентитет, а f.g символизира
;композицията на две функции.
;(define str (compose-stream ++))
;(map-stream (lambda (f) (f 1)) str) -> [1 2 3 4 5 ... ]

(define (repeated f n)
  (if (= n 0)
      (lambda (x) x)
      (lambda (x) (f ((repeated f (- n 1)) x)))))

(define (compose-stream-gen f n)
  (cons-stream (repeated f n)
               (compose-stream-gen f (+ n 1))))

(define (compose-stream f) (compose-stream-gen f 0))

(define (++ x) (+ x 1))
(define str (compose-stream ++))
(take 5 (map-stream (lambda (f) (f 1)) str)); -> [1 2 3 4 5 ... ]
