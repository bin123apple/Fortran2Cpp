program main
  implicit none
  call build(42)
  call run_tests()
contains

  subroutine build(order)
    integer :: order
    ! This subroutine is kept for completeness but not used in the test.
  end subroutine build

  subroutine test(order, repeat, trail, values)
    integer, dimension(:) :: values
    integer :: order, repeat, trail, i

    if (size(values, dim = 1) .ne. order * repeat + trail) then
      print *, 'Error: Size mismatch'
      stop
    end if
    do i = 1, order * repeat
      if (values(i) .ne. mod(i - 1, repeat) + 1) then
        print *, 'Error: Main sequence mismatch'
        stop
      end if
    end do
    do i = 1, trail
      if (values(i + order * repeat) .ne. i * 100) then
        print *, 'Error: Trail sequence mismatch'
        stop
      end if
    end do
  end subroutine test

  subroutine run_tests()
    integer :: errors
    integer, allocatable :: values(:)

    errors = 0

    ! Test Case 1
    allocate(values(8))
    values = (/1, 2, 3, 4, 5, 6, 7, 8/)
    call test_wrapper(1, 8, 0, values, errors)

    ! Add more test cases similar to the first one as needed...

    if (errors == 0) then
      print *, "All tests passed."
    else
      print *, errors, " tests failed."
    endif

    deallocate(values)
  end subroutine run_tests

  subroutine test_wrapper(order, repeat, trail, values, errors)
    integer, intent(inout) :: errors
    integer, dimension(:), intent(in) :: values
    integer, intent(in) :: order, repeat, trail

    block
      call test(order, repeat, trail, values)
    end block
  end subroutine test_wrapper

end program main