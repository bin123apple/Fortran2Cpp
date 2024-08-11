! file: test.f90
program test
  implicit none
  integer :: i
  
  i = 2000
  call test_i(i)
  
contains
  subroutine test_i(i)
    integer, intent(in) :: i
    if (i == 2000) then
      print *, 'Test passed: i =', i
    else
      print *, 'Test failed: i =', i
    end if
  end subroutine test_i
end program test