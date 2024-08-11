program test_interv
    implicit none
    real*8 :: x
    integer :: lxt, left, mflag
    real*8, dimension(:), allocatable :: xt

    ! Example data
    lxt = 5
    allocate(xt(lxt))
    xt = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    x = 3.5d0

    call interv(xt, lxt, x, left, mflag)

    print *, 'left:', left, 'mflag:', mflag

contains

subroutine interv ( xt, lxt, x, left, mflag )
      implicit real*8 (a-h,o-z)
      integer left, lxt, mflag, ihi, ilo, istep, middle
      real*8 x, xt(lxt)
      data ilo /1/
      save ilo  
      ihi = ilo + 1
      if (ihi .lt. lxt)                 go to 20
         if (x .ge. xt(lxt))            go to 110
         if (lxt .le. 1)                go to 90
         ilo = lxt - 1
         ihi = lxt
   20 if (x .ge. xt(ihi))               go to 40
      if (x .ge. xt(ilo))               go to 100
      istep = 1
   31    ihi = ilo
         ilo = ihi - istep
         if (ilo .le. 1)                go to 35
         if (x .ge. xt(ilo))            go to 50
         istep = istep*2
                                        go to 31
   35 ilo = 1
      if (x .lt. xt(1))                 go to 90
                                        go to 50
   40 istep = 1
   41    ilo = ihi
         ihi = ilo + istep
         if (ihi .ge. lxt)              go to 45
         if (x .lt. xt(ihi))            go to 50
         istep = istep*2
                                        go to 41
   45 if (x .ge. xt(lxt))               go to 110
      ihi = lxt
   50 middle = (ilo + ihi)/2
      if (middle .eq. ilo)              go to 100
      if (x .lt. xt(middle))            go to 53
         ilo = middle
                                        go to 50
   53    ihi = middle
                                        go to 50
   90 mflag = -1
      left = 1
                                        return
  100 mflag = 0
      left = ilo
                                        return
  110 mflag = 1
      if (x .eq. xt(lxt)) mflag = 0
      left = lxt
  111 if (left .eq. 1)                  return
      left = left - 1
      if (xt(left) .lt. xt(lxt))        return
                                        go to 111
      end
end program test_interv