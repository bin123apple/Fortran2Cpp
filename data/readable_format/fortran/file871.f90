program test
      dimension a(10)
      write(*,*) 'This is a test.'
      call sub(a,10)
      do 10, i=1,10
         if (a(i) .ne. i) then
            write(*,*) 'Test failed at index:', i
            stop
         endif
10    continue
      write(*,*) 'Test passed.'
      write(*,*) a
      stop
      end

      subroutine sub(a,n)
      dimension a(n)
      do 100 i = 1, n 
        a(i) = i
100   continue
      return
      end