program swap_numbers_internal_subroutine
  implicit none
  real :: a=2., b=3.

  call test_swap(a, b)

contains

  subroutine swap(x, y)
    real, intent(inout) :: x, y
    real aux
    aux=x; x=y; y=aux
  end subroutine swap

  subroutine test_swap(a, b)
    real, intent(inout) :: a, b  ! Corrected intent to inout
    real :: original_a, original_b

    original_a = a
    original_b = b

    call swap(a, b)

    if (a == original_b .and. b == original_a) then
      print*, "Test Passed: a and b were successfully swapped."
    else
      print*, "Test Failed: a and b were not swapped correctly."
    endif
  end subroutine test_swap

end program swap_numbers_internal_subroutine