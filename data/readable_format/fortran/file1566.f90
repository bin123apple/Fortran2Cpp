module annelid_test_b

  use, intrinsic :: iso_c_binding
  implicit none
  
  private
  public :: annelid_test

contains

  pure function annelid_test() bind(c)
    integer(kind = c_int) :: annelid_test

    annelid_test = 42
  end function annelid_test

end module annelid_test_b

program test_annelid_test_b
  use annelid_test_b
  implicit none

  integer :: result

  result = annelid_test()
  if (result == 42) then
    print *, "Test passed: annelid_test() returned 42."
  else
    print *, "Test failed: annelid_test() did not return 42."
  end if

end program test_annelid_test_b