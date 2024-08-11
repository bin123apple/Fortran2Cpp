program test_ludcmp
  implicit none
  integer, parameter :: n = 3, np = 3
  real(8) :: a(np,np), d
  integer :: indx(n)
  integer :: i, j

  ! Define a 3x3 test matrix
  data a /1.0d0, 2.0d0, 3.0d0, &
          2.0d0, 3.0d0, 4.0d0, &
          3.0d0, 4.0d0, 5.0d0/

  call ludcmp(a, n, np, indx, d)

  ! Output the decomposed matrix for verification
  do i = 1, n
    do j = 1, n
      write(*,*) 'a(', i, ',', j, ') = ', a(i,j)
    end do
  end do

contains

  subroutine ludcmp(a,n,np,indx,d)
    implicit none
    integer, intent(in) :: n, np
    real(8), dimension(np,np), intent(inout) :: a
    integer, dimension(n), intent(out) :: indx
    real(8), intent(out) :: d
    integer :: i, j, imax, k
    real(8) :: big, dum, sum, temp
    real(8), dimension(n) :: vv

    d = 1.0d0
    do i = 1, n
      big = 0.0d0
      do j = 1, n
        if (abs(a(i,j)) > big) then
          big = abs(a(i,j))
        endif
      end do
      if (big == 0.0d0) pause 'Singular matrix'
      vv(i) = 1.0d0 / big
    end do

    do j = 1, n
      do i = 1, j-1
        sum = a(i,j)
        do k = 1, i-1
          sum = sum - a(i,k)*a(k,j)
        end do
        a(i,j) = sum
      end do
      big = 0.0d0
      do i = j, n
        sum = a(i,j)
        do k = 1, j-1
          sum = sum - a(i,k)*a(k,j)
        end do
        a(i,j) = sum
        dum = vv(i) * abs(sum)
        if (dum >= big) then
          big = dum
          imax = i
        endif
      end do
      if (j /= imax) then
        do k = 1, n
          dum = a(imax,k)
          a(imax,k) = a(j,k)
          a(j,k) = dum
        end do
        d = -d
        vv(imax) = vv(j)
      endif
      indx(j) = imax
      if (a(j,j) == 0.0d0) a(j,j) = 1.0d-20
      if (j /= n) then
        dum = 1.0d0 / a(j,j)
        do i = j+1, n
          a(i,j) = a(i,j) * dum
        end do
      endif
    end do
  end subroutine ludcmp

end program test_ludcmp