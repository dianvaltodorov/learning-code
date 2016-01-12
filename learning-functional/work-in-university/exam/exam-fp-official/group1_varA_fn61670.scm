;include
(define (foldl op nv l)
  (if (null? l)
       nv
      (foldl op (op nv (car l)) (cdr l))))

(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

;===========================================
;                 Solutions
;===========================================

;------------------------------------------
;TASK 1
;------------------------------------------

(define (meetTwice? f g a b)
  (define (helper i res)
    (cond ((> i b) res)
          ((and (= (f i) (g i))) (helper (+ i 1) (+ res 1)))
          (else (helper (+ i 1) res))))
  (>= (helper a 0) 2))

;(meetTwice? (lambda(x) x) (lambda(x) (- x)) -3 1)
;(meetTwice? (lambda(x) x) sqrt 0 5)

;------------------------------------------
;TASK 2
;------------------------------------------
(define (count x lst)
  (length (filter (lambda(el) (equal? x el)) lst)))

(define (maximum l)
  (if (null? l)
      #f
      (foldl max (car l) (cdr l))))

(define (occurs? x l)
  (cond((null? l) #f)
       ((= x (car l)) #t)
       (else (occurs? x (cdr l)))))

(define (make-set-of-duplicates l)
  (define (helper res l)
    (cond ((null? l) res)
          ((occurs? (car l) res) (helper res (cdr l)))
          (else (helper (append res (list (car l))) (cdr l)))))
  (helper '() l))

(define (get-duplicates lst)
  (filter (lambda(x) (> (count x lst) 1)) lst))

(define (maxDuplicate ll)
  (maximum (apply append (map (lambda (l) (make-set-of-duplicates (get-duplicates l))) ll))))

;Tests:
;--------
;(define ll1 '((1 2 3 2) (-4 -4) (5)))
;(define ll2 '((1 2 3) (-4 -5 -6) ()))
;(maxDuplicate ll1)
;(maxDuplicate ll2)

;------------------------------------------
;TASK 3
;------------------------------------------
(define (checkMatrix? m k)
  ( = 1
      (apply *
             (map (lambda (row) (if (not (null? (filter (lambda (x) (= 0 (remainder x 3))) row))) 1 0))
                  m))))
;Tests:
;--------
;(define mat1 '((1 2 6) (3 8 9) (10 12 11)))
;(define mat2 '((1 2 4) (3 8 9) (10 12 11)))
;(checkMatrix? mat1 3)
;(checkMatrix? mat2 3)

;------------------------------------------
;TASK 4
;------------------------------------------
(define ldp1 '(1 2 3 4))
(define ldp2 '(4 3 2 1 10))

(define (find-descneding-prefix l)
  (define (helper x l res)
   (cond ((null? l) res)
         ((< x (car l)) res)
         (else (helper (car l) (cdr l) (append res (list (car l)))))))
  (if (null? l)
      '()
      (helper (car l) (cdr l) (list (car l)))))


(define (longestDescending l)
  (define (helper res l)
    (cond ((null? l) res)
          ((> (length (find-descneding-prefix l)) (length res)) (helper (find-descneding-prefix l) (cdr l)))
          (else (helper res (cdr l)))))
  (helper '() l))

;Tests:
;-------
;(define ll1 '((1 2 3 2) (-4 -4) (5)))
;(define ll2 '((1 2 3) (-4 -5 -6) ()))
;(find-descneding-prefix '())
;(find-descneding-prefix ldp2)
;(find-descneding-prefix ldp1)
;(find-descneding-prefix '(984 8 7 6 5 -1 4 2 6 7))
;(define ld1 '(5 3 8 6 4 2 6 7 1))
;(define ld2 '(1 2 3 4 5 6))
;(longestDescending ld1)
;(longestDescending ld2)
;(longestDescending '(1 725 72 1 17 8 984 8 7 6 5 -1 4 2 6 7))
