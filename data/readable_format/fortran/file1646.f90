program test_dswap
  implicit none
  double precision, allocatable :: dx(:), dy(:)
  integer :: N, strideX, strideY

  ! Example unit test for dswap subroutine
  N = 3
  allocate(dx(N), dy(N))
  dx = [1.0d0, 2.0d0, 3.0d0]
  dy = [4.0d0, 5.0d0, 6.0d0]
  strideX = 1
  strideY = 1

  call dswap(N, dx, strideX, dy, strideY)

  print *, 'Fortran code: Test passed if dx and dy are swapped correctly.'
  print *, 'dx = ', dx
  print *, 'dy = ', dy

  ! Add more tests here as needed

  deallocate(dx, dy)
  
contains

  subroutine dswap(N, dx, strideX, dy, strideY)
    implicit none
    integer, intent(in) :: N, strideX, strideY
    double precision, intent(inout) :: dx(*), dy(*)
    double precision :: tmp
    integer :: i, ix, iy
    
    if (N <= 0) return
    
    if (strideX == 1 .AND. strideY == 1) then
      do i = 1, N
        tmp = dx(i)
        dx(i) = dy(i)
        dy(i) = tmp
      end do
    else
      ix = 1
      iy = 1
      do i = 1, N
        tmp = dx(ix)
        dx(ix) = dy(iy)
        dy(iy) = tmp
        ix = ix + strideX
        iy = iy + strideY
      end do
    endif
  end subroutine dswap

end program test_dswap