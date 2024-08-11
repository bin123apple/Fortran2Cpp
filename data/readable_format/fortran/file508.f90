! t_test.f90
program t_test
  implicit none
  integer :: i
  
  ! Test case 1: i = 1
  i = 1
  call test(i, 1)
  
  ! Test case 2: i = 2
  i = 2
  call test(i, 2)
  
  ! Test case 3: i = 3
  i = 3
  call test(i, 3)
  
contains

  subroutine test(i, expected)
    integer, intent(in) :: i, expected
    if (i.eq.1) then
      if (1 .eq. expected) then
        print *, "Test passed for i =", i
      else
        print *, "Test failed for i =", i
      end if
    else if (i.eq.2) then
      if (2 .eq. expected) then
        print *, "Test passed for i =", i
      else
        print *, "Test failed for i =", i
      end if
    else
      if (3 .eq. expected) then
        print *, "Test passed for i =", i
      else
        print *, "Test failed for i =", i
      end if
    end if
  end subroutine test
  
end program t_test