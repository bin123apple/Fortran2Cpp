program test
      character*72 c
      logical test_passed
      test_passed = .TRUE.
      
      write(c,8000)
8000  format(36(2H!!))

      do i = 1,72,2
         if (c(i:i+1) /= '!!') then
            test_passed = .FALSE.
            exit
         endif
      end do
      
      if (test_passed) then
         print *, "Test Passed: All characters are !!"
      else
         print *, "Test Failed: Not all characters are !!"
      endif
      
      end