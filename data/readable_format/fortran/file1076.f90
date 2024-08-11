module annelid_test_a

  use, intrinsic :: iso_c_binding
  implicit none
  
  private
  public :: annelid_test

contains

  pure function annelid_test () bind(c)
    integer (kind = c_int) :: annelid_test

    annelid_test = 23
  end function annelid_test

end module annelid_test_a

program test_annelid_test
  use annelid_test_a
  use, intrinsic :: iso_c_binding, only: c_int
  implicit none
  
  integer(kind=c_int) :: result
  
  result = annelid_test()
  if (result == 23) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
end program test_annelid_test