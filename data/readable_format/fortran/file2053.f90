program dec_char_conversion_test
  implicit none
  integer :: i
  real :: x
  character(len=10) :: str

  ! Call the subroutine that assigns values
  call assign_values(i, x, str)

  ! Output the results
  print *, 'Integer i = ', i
  print *, 'Real x = ', x
  print *, 'String str = ', str

  ! Perform the tests
  call perform_tests(i, x, str)

contains

  ! This subroutine assigns the values to variables
  subroutine assign_values(i, x, str)
    integer, intent(out) :: i
    real, intent(out) :: x
    character(len=10), intent(out) :: str

    i = 42
    x = 3.14
    str = 'Hello'
  end subroutine assign_values

  ! This subroutine performs simple tests to verify variable assignments
  subroutine perform_tests(i, x, str)
    integer, intent(in) :: i
    real, intent(in) :: x
    character(len=*), intent(in) :: str

    ! Test for i
    if (i == 42) then
      print *, 'Test i passed'
    else
      print *, 'Test i failed'
    endif

    ! Test for x
    if (x == 3.14) then
      print *, 'Test x passed'
    else
      print *, 'Test x failed'
    endif

    ! Test for str
    if (str == 'Hello') then
      print *, 'Test str passed'
    else
      print *, 'Test str failed'
    endif
  end subroutine perform_tests

end program dec_char_conversion_test