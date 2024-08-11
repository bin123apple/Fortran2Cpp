subroutine xsetun (lun)
      integer lun, mesflg, lunit
      common /eh0001/ mesflg, lunit
      if (lun .gt. 0) lunit = lun
      return
      end

      program testxsetun
      integer mesflg, lunit
      common /eh0001/ mesflg, lunit

      call xsetun(-1)
      if (lunit .eq. 0) then
          print *, 'Test 1 passed.'
      else
          print *, 'Test 1 failed.'
      endif

      call xsetun(5)
      if (lunit .eq. 5) then
          print *, 'Test 2 passed.'
      else
          print *, 'Test 2 failed.'
      endif

      end program testxsetun