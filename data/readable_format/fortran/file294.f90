program main
   call test()
contains
   subroutine compute(a, b, d)
      integer, intent(out) :: d
      integer, dimension(100,100), intent(out) :: a, b
      integer :: i, j

      do i=1,100
         do j=1,100
            a(i,j) = 1
            b(i,j) = 2
            a(i,j) = a(i,j) + b(i,j)
         end do
      end do

      d = sum(a)
   end subroutine compute

   subroutine test()
      integer :: a(100,100), b(100,100), d
      call compute(a, b, d)
      print *, "Test sum: ", d
      ! Here you would compare 'd' with the expected value, which is 30000
      if (d == 30000) then
         print *, "Test passed."
      else
         print *, "Test failed."
      end if
   end subroutine test
end program main