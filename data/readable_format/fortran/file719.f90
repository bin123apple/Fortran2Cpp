! caps_module.f90
module caps_module
  implicit none
contains
  subroutine caps(file_name)
    intrinsic Len, Index, AdjustL
    character(len=*), intent(inout) :: file_name
    character(len=Len(file_name)) :: temp_name
    character(len=26) :: low_case = "abcdefghijklmnopqrstuvwxyz", &
                         up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    integer :: ii, j

    temp_name = ""
    j = 0

    temp_name = file_name

    do ii = 1, Len(file_name)
      j = Index(up_case, file_name(ii:ii))
      if (j /= 0) temp_name(ii:ii) = low_case(j:j)
    end do

    temp_name = AdjustL(temp_name)
    file_name = temp_name
  end subroutine caps
end module caps_module

! test_caps.f90
program test_caps
  use caps_module
  implicit none
  character(len=30) :: test_string

  ! Test 1: Convert uppercase to lowercase
  test_string = "HELLO WORLD"
  call caps(test_string)
  if (test_string == "hello world") then
    print *, "Test 1 Passed."
  else
    print *, "Test 1 Failed."
  endif

  ! Test 2: Trim leading spaces and convert to lowercase
  test_string = "  HELLO WORLD.TXT"
  call caps(test_string)
  if (test_string == "hello world.txt") then
    print *, "Test 2 Passed."
  else
    print *, "Test 2 Failed."
  endif
end program test_caps