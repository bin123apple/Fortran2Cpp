program test
      character*6 c
      write (c,1001) 1
      if (c .ne. '    1 ') then
        print *, 'Test failed'
        call abort
      else
        print *, 'Test passed'
      endif

 1001 format (' ',i4' ')
      end