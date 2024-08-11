program test_sdsdot
  implicit none
  real :: result
  real, dimension(5) :: sx = [1.0, 2.0, 3.0, 4.0, 5.0]
  real, dimension(5) :: sy = [1.0, 1.0, 1.0, 1.0, 1.0]
  real :: sb
  integer :: N, strideX, strideY

  ! Test 1
  N = 5
  sb = 0.0
  strideX = 1
  strideY = 1
  result = sdsdot(N, sb, sx, strideX, sy, strideY)
  print *, "Test 1 (Basic): Expected 15.0, Got", result

  ! Test 2 - With Scaling Factor
  sb = 2.0
  result = sdsdot(N, sb, sx, strideX, sy, strideY)
  print *, "Test 2 (Scaling): Expected 17.0, Got", result

  ! Test 3 - With Strides
  strideX = 2
  strideY = 2
  N = 3  ! Adjust N due to stride, to avoid accessing out of bounds
  result = sdsdot(N, sb, sx, strideX, sy, strideY)
  print *, "Test 3 (Strides): Expected 8.0, Got", result

contains

  real function sdsdot(N, sb, sx, strideX, sy, strideY)
    implicit none
    integer, intent(in) :: N, strideX, strideY
    real, intent(in) :: sb
    real, intent(in) :: sx(*), sy(*)
    double precision :: dtemp
    integer :: i, ix, iy
    dtemp = dble(sb)
    ix = 1
    iy = 1
    if (strideX == 1 .and. strideY == 1) then
       do i = 1, N
          dtemp = dtemp + dble(sx(i)) * dble(sy(i))
       end do
    else
       do i = 1, N
          dtemp = dtemp + dble(sx(ix)) * dble(sy(iy))
          ix = ix + strideX
          iy = iy + strideY
       end do
    endif
    sdsdot = real(dtemp)
  end function sdsdot

end program test_sdsdot