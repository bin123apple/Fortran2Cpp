program test_arithmetic_if
      integer A, x
      A = -1 ! Test case 1: A < 0
      x = 0
      if (A) 100, 200, 300
100   CONTINUE
      x = x + 1
      goto 400
200   CONTINUE
      x = x + 2
      goto 400
300   CONTINUE
      x = x + 3
400   CONTINUE
      print *, 'Test Case with A = ', A, 'results in x =', x
      end