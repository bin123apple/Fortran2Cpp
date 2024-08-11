module my_mod
  contains
    integer function my_func()
      my_func = 10
    end function my_func
end module my_mod

subroutine workshare(aa, bb, cc, dd, ee, ff, n)
  use my_mod
  integer :: n
  real, dimension(n) :: aa, bb, cc, dd, ee, ff
  integer :: i

  aa = my_func()
  cc = dd
  ee = ff

  do i = 1, n
    if (aa(i) /= my_func()) aa(i) = bb(i) * cc(i)
    if (dd(i) < 5) dd(i) = aa(i) * my_func()
    if (aa(i) >= my_func()) cc(i) = aa(i) + my_func()
    if (aa(i) <= my_func()) cc(i) = dd(i) + my_func()
  end do

  do i = 1, n
    if (i <= my_func()) aa(i) = aa(i) + bb(i)
  end do
end subroutine workshare

program test
  use my_mod
  implicit none
  integer, parameter :: n = 10
  real, dimension(n) :: aa, bb, cc, dd, ee, ff
  integer :: i

  ! Initialize arrays
  do i = 1, n
    bb(i) = real(i) * 2.0
    dd(i) = real(i) * 3.0
    ff(i) = real(i) * 4.0
  end do

  call workshare(aa, bb, cc, dd, ee, ff, n)

  ! Output results for manual verification
  print *, "aa:", aa
  print *, "cc:", cc
  print *, "dd:", dd
end program test