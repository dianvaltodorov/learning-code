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
