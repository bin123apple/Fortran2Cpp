! File: single_file_test.f90
program single_file_test
  implicit none

  ! Type definition within the same file
  type :: aot_fun_type
    integer :: handle = 0
    integer :: arg_count = 0
  end type aot_fun_type

  type(aot_fun_type) :: default_fun
  type(aot_fun_type) :: custom_fun

  ! Test default initialization
  if (default_fun%handle == 0 .and. default_fun%arg_count == 0) then
    print *, "PASS: Default initialization"
  else
    print *, "FAIL: Default initialization"
  end if

  ! Setting custom values for testing
  custom_fun%handle = 10
  custom_fun%arg_count = 5

  ! Test custom initialization
  if (custom_fun%handle == 10 .and. custom_fun%arg_count == 5) then
    print *, "PASS: Custom initialization"
  else
    print *, "FAIL: Custom initialization"
  end if

end program single_file_test