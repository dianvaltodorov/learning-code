(define (f x n)
  (define (helper i p q result)
    (if(> i (+ n 1))
       (+ result (/ p q))
       (helper (+ i 1)
               (* p x)
               (* q i)
               (+ result (/ p q)))))
  (helper 1 1 1 0))


  (define (f2 n x)
    (define (helper i current sum)
      (if(> i n)
         sum
         (helper (+ i 1)
                 (* x current)
                 (+ sum (* i current)))))
    (helper 0 1 0))


  ;(define x 3)
  ;((lambda (x) (+ x 1)) 3)
  ;(lambda (x) x)

  ;ламбдии
  (define (S1 a b c)
    ((lambda (p)
            (sqrt (* p
                     (- p a)
                     (- p b)
                     (- p c))))
    (/ (+ a b c) 2)))

  (define (S2 a b c)
    (let ((p (/ (+ a b c) 2)))
      (sqrt (* p
               (- p a)
               (- p b)
               (- p c)))))

  (define (S3 a b c)
     (let* ((P (+ a b c))
            (p (/ P 2)))
     (sqrt (* p
              (- p a)
              (- p b)
              (- p c)))))

  (define (solve a b c)
    (let* ((sqb (* b b))
           (4ac (* 4 a c))
           (2a (* 2 a))
           (D (- sqb 4ac))
           (rD (sqrt D))
           (x1 (/ (+ (- b) rD) 2a))
           (x2 (/ (- (- b) rD) 2a)))
      (list x1 x2)))


  (define (solve2 a b c)
    (let* ((D (- (* b b) (* 4 a c)))
           (x1 (/ (+ (- b) (sqrt D))
                  (* 2 a)))
           (x2 (/ (- (- b) (sqrt D))
                  (* 2 a))))
    (list x1 x2)))

  ((lambda (x) (+ x 1)) 3)

  (define (solve3 a b c)
    ((lambda(D) (list
                      ((lambda() (/ (- (- b) (sqrt D)) (* 2 a))))
                      ((lambda() (/ (+ (- b) (sqrt D)) (* 2 a))))))
     (- (* b b) (* 4 a c))))

  ;(solve3 1 -1 -12)

  ;Наредена двойка
  (define (mcons a b)
    (lambda (f)
      (if(eq? f "car")
         a
         b)))

  (define (mcar pair) (pair "car"))
  (define (mcdr pair) (pair "cdr"))

  (define yolo  (mcons 2 (mcons 3 (mcons 4 5))))
  ((mcdr yolo) "car")
  (mcdr yolo)
  (mcar (mcdr yolo))


  ;Eстествени числа
  (define n0 (lambda() 'null))
  (define (inc x)
    (lambda () x))
  (define (dec x)
    (x))

  (define n1 (inc n0))
  (define n2 (inc n1))
  (define n3 (inc n2))
  (define n4 (inc n3))
  (define n5 (inc n4))
  (define n6 (inc n5))

  (define (isZero? n)
    (eq? (n) 'null))

  (define (isEqual? x y)
    (cond
      ((isZero? x) (isZero? y))
      ((isZero? y) (isZero? x))
      (else (isEqual?
             (dec x)
             (dec y)))))

  (define (plus x y)
   (if (isZero? y)
       x
       (plus(inc x) (dec y))))

  (isZero? n0)

  (isEqual? (plus n3 n2) n5)

  (isEqual?
   (plus (plus n3 n2) n5)
   (plus (plus n4 n2) n4))
