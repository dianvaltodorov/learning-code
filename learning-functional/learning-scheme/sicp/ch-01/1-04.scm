(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

Returns a + b when b is positive. Otherwise return a - b