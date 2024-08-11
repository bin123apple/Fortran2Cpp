program test_select_case
  integer :: nn

  ! Test cases
  nn = 1
  call testCase(nn)
  nn = 2
  call testCase(nn)
  nn = 3  ! This will test a value that doesn't match any case.
  call testCase(nn)

contains

  subroutine testCase(nn)
    integer, intent(in) :: nn
    select case(nn)
    case(1)
      write(*,*) "case1"
    case(2)
      write(*,*) "case2"
    case default
      ! Explicitly handling default case to match C++ behavior,
      ! but not producing any output to align with the initial Fortran logic.
    end select
  end subroutine testCase

end program test_select_case