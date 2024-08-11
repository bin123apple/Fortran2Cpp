program test_normsplin
      implicit none
      integer n
      parameter (n = 800)
      real*8 x_norm(0:3,1:n), y_norm(0:3,1:n)
      real*8 dx
      common /normsplin/ x_norm, y_norm, dx
      
      integer i, j

      ! Initialize values
      dx = 1.23d0
      do i = 0, 3
         do j = 1, n
            x_norm(i, j) = dble(i * j)
            y_norm(i, j) = dble(i + j)
         end do
      end do

      ! Print some values to verify
      print *, 'dx = ', dx
      print *, 'x_norm(0,1) = ', x_norm(0,1)
      print *, 'y_norm(0,1) = ', y_norm(0,1)
      print *, 'x_norm(3,n) = ', x_norm(3,n)
      print *, 'y_norm(3,n) = ', y_norm(3,n)

end program test_normsplin