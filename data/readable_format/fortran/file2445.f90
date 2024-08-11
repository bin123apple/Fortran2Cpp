program test_map
  implicit none
  integer, parameter :: n = 20
  integer :: a(n), b(n)

  ! Explicitly initialize arrays a and b
  call initialize_arrays(a, b, n)

  ! Call the map subroutine
  call map(a, b, n)

  ! Check results
  call check(a, b, n)

  print *, "All tests passed successfully!"

contains

  subroutine map(a, b, n)
    integer, intent(inout) :: a(n), b(n)
    integer, intent(in)    :: n
    integer :: i

    ! Initialize arrays
    do i = 1, n
       a(i) = i
    end do

    do i = 1, n
       b(i) = i
    end do
  end subroutine map

  subroutine check(a, b, n)
    integer, intent(in) :: a(n), b(n), n
    integer :: i

    do i = 1, n
       if (a(i) /= b(i)) then
          print *, "Test failed at index", i
          stop
       endif
    end do
  end subroutine check

  subroutine initialize_arrays(a, b, n)
    integer, intent(out) :: a(n), b(n)
    integer, intent(in)  :: n
    integer :: i

    do i = 1, n
       a(i) = 0
       b(i) = 0
    end do
  end subroutine initialize_arrays

end program test_map