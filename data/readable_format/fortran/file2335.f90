module imgcpy_module
  contains
    subroutine imgcpy(ia, npix, nlines, ib)
      integer*2, intent(in) :: ia(npix, nlines)
      integer*2, intent(out) :: ib(npix, nlines)
      integer :: i, j

      do j = 1, nlines
         do i = 1, npix
            ib(i, j) = ia(i, j)
         end do
      end do
    end subroutine imgcpy
end module imgcpy_module

program test_imgcpy
  use imgcpy_module
  implicit none

  integer*2, dimension(3, 3) :: ia = reshape([1, 2, 3, 4, 5, 6, 7, 8, 9], [3, 3])
  integer*2, dimension(3, 3) :: ib
  integer :: i, j

  call imgcpy(ia, 3, 3, ib)

  print *, "Copied matrix:"
  do j = 1, 3
     do i = 1, 3
        print *, ib(i, j)
     end do
  end do
end program test_imgcpy