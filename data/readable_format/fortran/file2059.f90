module foo_mod
  implicit none
  integer :: c1, c2, c3
contains
  subroutine foo(tmp1, tmp2, tmp3)
    integer, parameter :: n = 100
    real :: tmp1(n,2), tmp2(n), tmp3(n)
    integer :: i
    logical :: cond

    c2 = c3
    cond = c1 .eq. 1 .and. c3 .eq. 1
    do i = 1,100
      if (cond) tmp2(i) = tmp1(i,1) / tmp1(i,2)
    end do
    do i = 1,100
      if (cond) tmp3(i) = tmp2(i)
    end do
  end subroutine foo
end module foo_mod

program testFoo
  use foo_mod
  implicit none
  integer, parameter :: n = 100
  real :: tmp1(n, 2), tmp2(n), tmp3(n)
  integer :: i

  ! Set values for c1, c2, and c3
  c1 = 1
  c2 = 1
  c3 = 1

  ! Initialize tmp1 for testing
  do i = 1, n
    tmp1(i, 1) = i
    tmp1(i, 2) = i + 1
  end do

  ! Call the subroutine
  call foo(tmp1, tmp2, tmp3)

  ! Check results
  do i = 1, n
    if (tmp2(i) /= tmp1(i, 1) / tmp1(i, 2) .or. tmp3(i) /= tmp2(i)) then
      print *, "Test failed at index:", i
      stop
    end if
  end do

  print *, "All tests passed."
end program testFoo