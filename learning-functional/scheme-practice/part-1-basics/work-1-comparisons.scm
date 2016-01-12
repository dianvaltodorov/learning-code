(= 2 3) ; #f
(= 2 2) ; #t
(= '(1 2) '(1 2)) ;f


(define x '(2 3))
(define y '(2 3))
(eq? x y)        ;=> #f
(define y x)
(eq? x y)       ;=> #t
(define x '())
(define y '())
(eq? x y)      => #t
