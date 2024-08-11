program test_program
  implicit none

  call run_unit_tests

contains

  function test1(r, step) result(k)
    integer, intent(in) :: r, step
    integer :: k, n
    k = 0
    do n = HUGE(n) - r, HUGE(n), step
      k = k + 1
    end do
  end function test1

  subroutine test2(lim, step)
    integer, intent(in) :: lim, step
    integer :: k, n
    k = 0
    do n = 1, lim, step
      k = k + 1
    end do
    if (k /= 0) call abort
  end subroutine test2

  subroutine run_unit_tests
    if (test1(10, 1) /= 11) call abort
    if (test1(10, 2) /= 6) call abort
    if (test1(9, 2) /= 5) call abort

    call test2(0, 1)
    call test2(0, 2)
    call test2(2, -1)
    call test2(2, -2)

    print *, "All Fortran unit tests passed successfully."
  end subroutine run_unit_tests

end program test_program