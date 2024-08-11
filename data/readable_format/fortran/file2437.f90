module mod_interface
  implicit none
contains
  function add(a, b) result(c)
    integer, intent(in) :: a, b
    integer :: c

    c = a + b
  end function add
end module mod_interface

program main
  use mod_interface
  implicit none
  integer :: result

  ! Main program usage of the add function
  result = add(2, 3)
  print *, "2 + 3 =", result

  ! Call the test procedure
  call test_add()
contains
  subroutine test_add()
    use mod_interface
    implicit none
    integer :: expected
    integer :: test_result

    ! Setup
    expected = 5

    ! Execution
    test_result = add(2, 3)

    ! Verification
    if (test_result == expected) then
      print *, "Test passed."
    else
      print *, "Test failed: Expected", expected, "but got", test_result
    end if
  end subroutine test_add
end program main