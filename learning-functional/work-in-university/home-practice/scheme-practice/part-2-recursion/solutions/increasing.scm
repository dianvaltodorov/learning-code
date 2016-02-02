(load "../../lib/unit.scm")

(load "count_digits.scm")
(load "digit_at_position.scm")

(define (increasing? x)
  (define (helper x position)
  (cond
    ((= position (count-digits-iter x)) #t)
    ((< (digit-at-pos x position)
        (digit-at-pos x (+ position 1))) (helper x (+ position 1)))
    (else #f)))
  (helper x 1))
