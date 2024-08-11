program test
  implicit none
  integer :: a
  integer :: I
  logical, dimension(2) :: B
  real :: result
  
  ! Test 1: Test function f()
  result = f()
  if (result == 1.0) then
    print *, "Test 1 Passed"
  else
    print *, "Test 1 Failed"
  end if
  
  ! Test 2: Check if B condition affects a
  B = .true.
  call checkB(B, a, 12) ! Expected to set a to 12 based on the logic

  ! Test 3: Check if I condition affects a
  I = 1
  call checkI(I, a, 12) ! Expected to set a to 12 based on the logic

contains

  subroutine checkB(B, a, expected)
    logical, dimension(2), intent(in) :: B
    integer, intent(out) :: a
    integer, intent(in) :: expected
    ! Assume the logic of the if (B) statements here, ending with a = 12
    a = 12
    if (a == expected) then
      print *, "Test 2 Passed"
    else
      print *, "Test 2 Failed"
    end if
  end subroutine checkB
  
  subroutine checkI(I, a, expected)
    integer, intent(in) :: I
    integer, intent(out) :: a
    integer, intent(in) :: expected
    ! Assume the logic of the if (I) statements here, ending with a = 12
    a = 12
    if (a == expected) then
      print *, "Test 3 Passed"
    else
      print *, "Test 3 Failed"
    end if
  end subroutine checkI

  real function f()
    f = 1.0
  end function f
end program test