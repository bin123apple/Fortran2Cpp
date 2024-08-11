program test_minimax
      implicit none

      real*8 :: x(5) = [1.5, -2.3, 3.7, 0.1, -0.5]
      real*8 :: xmin, xmax
      integer :: numpts

      numpts = 5

      call minimax(x, xmin, xmax, numpts)

      print *, "Minimum: ", xmin
      print *, "Maximum: ", xmax

end program test_minimax

subroutine minimax(x, xmin, xmax, numpts)

      real*8 x(*)
      real*8 xmin, xmax
      integer numpts
      integer i

      xmax=x(1)
      xmin=xmax
      do i=1,numpts
         if (x(i).lt.xmin) xmin=x(i)
         if (x(i).gt.xmax) xmax=x(i)
      end do

      return
end