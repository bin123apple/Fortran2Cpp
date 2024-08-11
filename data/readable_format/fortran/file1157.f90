module iotk_fmt_interf
implicit none
private

public :: iotk_basefmt_x, iotk_wfmt_x

contains

! Example implementation of iotk_basefmt_x
function iotk_basefmt_x(type, ikind, ilen) result(formatted_string)
  character(len=*), intent(in) :: type
  integer, intent(in) :: ikind, ilen
  character(len=100) :: formatted_string
  
  ! Example logic (needs to be replaced with actual implementation)
  write(formatted_string, '(A, I0, A, I0)') trim(type), ikind, " Length: ", ilen
end function iotk_basefmt_x

! Example implementation of iotk_wfmt_x
function iotk_wfmt_x(type, ikind, isize, ilen, sep) result(formatted_string)
  character(len=*), intent(in) :: type
  integer, intent(in) :: ikind, isize, ilen
  character(len=*) :: sep
  character(len=150) :: formatted_string
  
  ! Example logic (needs to be replaced with actual implementation)
  write(formatted_string, '(A, I0, A, I0, A, A)') trim(type), ikind, " Size: ", isize, " Length: ", ilen, sep
end function iotk_wfmt_x

end module iotk_fmt_interf

program test_iotk_fmt
use iotk_fmt_interf
implicit none

character(len=100) :: result_basefmt
character(len=150) :: result_wfmt

! Test iotk_basefmt_x
result_basefmt = iotk_basefmt_x("TestType", 2, 20)
print *, "iotk_basefmt_x result: ", trim(result_basefmt)

! Test iotk_wfmt_x
result_wfmt = iotk_wfmt_x("TestTypeW", 3, 10, 30, "_Separator_")
print *, "iotk_wfmt_x result: ", trim(result_wfmt)

end program test_iotk_fmt