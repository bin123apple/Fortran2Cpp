program test_enum_fortran
  use, intrinsic :: iso_c_binding, only: c_int
  implicit none

  ! Define the enums
  enum, bind(c)
     enumerator :: sun, mon = 2, wed = 1
  end enum

  enum, bind(c)
     enumerator :: apple, mango
  end enum

  ! Test cases
  call verify_enum(sun, 0, "sun")
  call verify_enum(mon, 2, "mon")
  call verify_enum(wed, 1, "wed")
  call verify_enum(apple, 0, "apple")
  call verify_enum(mango, 1, "mango")

contains

  subroutine verify_enum(actual, expected, name)
    integer(kind=c_int), intent(in) :: actual, expected
    character(len=*), intent(in) :: name
    if (actual /= expected) then
      print *, "Test failed for ", name, ": expected ", expected, " but got ", actual
    else
      print *, "Test passed for ", name
    end if
  end subroutine verify_enum

end program test_enum_fortran