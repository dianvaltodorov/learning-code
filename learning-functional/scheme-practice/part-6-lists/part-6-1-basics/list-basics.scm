(define (mlist-ref items n)
  (if(= n 0)
     (car items)
     (mlist-ref cdr(items) (- n 1))))

(define (mlength items)
  (if (null? items)
      0
      (+ 1 (mlength (cdr items)))))


(define (length-i items)
  (define (helper a count)
    (if(null? a)
        count
        (helper (cdr a) (+ 1 count))))
  (helper items 0))


(define (last-pair items)
  (list-ref items (- (length items) 1)))


    
