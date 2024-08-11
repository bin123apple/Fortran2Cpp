! test_program.f90
module fm013_mod
  implicit none
contains
  subroutine fm013(iczero, ivdele)
    integer, intent(in) :: iczero
    integer, intent(inout) :: ivdele
    
    if (iczero == 0) then
      ivdele = ivdele + 1
    end if
  end subroutine fm013
end module fm013_mod

program test_fm013
  use fm013_mod
  implicit none
  
  integer :: iczero
  integer :: ivdele
  
  ! Test Case 1: ICZERO = 0 should increment IVDELE
  iczero = 0
  ivdele = 0
  call fm013(iczero, ivdele)
  print *, 'Test Case 1: ICZERO = 0, Expected IVDELE = 1, Actual IVDELE = ', ivdele
  
end program test_fm013