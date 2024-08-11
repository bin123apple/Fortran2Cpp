program test_dasumf
      implicit none
      double precision dx(6)
      double precision result
      integer i

      dx(1) = 1.0d0
      dx(2) = -2.0d0
      dx(3) = 3.0d0
      dx(4) = -4.0d0
      dx(5) = 5.0d0
      dx(6) = -6.0d0

      print *, 'Testing dasumf function:'
      result = dasumf(6, dx, 1)
      print *, 'Test case 1 (incx = 1): ', result  ! Expected: 21.0

      result = dasumf(3, dx, 2)
      print *, 'Test case 2 (incx = 2): ', result  ! Expected: 9.0 (1.0 + 3.0 + 5.0)

      result = dasumf(0, dx, 1)
      print *, 'Test case 3 (n = 0): ', result  ! Expected: 0.0

      contains

        double precision function dasumf(n, dx, incx)
        implicit none
        double precision dx(*)
        integer n, incx, i, m, mp1, nincx
        double precision dtemp

        dasumf = 0.0d0
        dtemp = 0.0d0
        if (n .le. 0 .or. incx .le. 0) return
        if (incx .eq. 1) goto 20

        nincx = n*incx
        do 10 i = 1, nincx, incx
           dtemp = dtemp + dabs(dx(i))
    10    continue
        dasumf = dtemp
        return

  20    m = mod(n,6)
        if (m .eq. 0) goto 40
        do 30 i = 1, m
           dtemp = dtemp + dabs(dx(i))
  30    continue
        if (n .lt. 6) goto 60
  40    mp1 = m + 1
        do 50 i = mp1, n, 6
           dtemp = dtemp + dabs(dx(i)) + dabs(dx(i + 1)) + dabs(dx(i + 2)) + &
                dabs(dx(i + 3)) + dabs(dx(i + 4)) + dabs(dx(i + 5))
  50    continue
  60    dasumf = dtemp
        return
        end function dasumf

      end program test_dasumf