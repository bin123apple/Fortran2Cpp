module modproc
  implicit none
  interface bar
    procedure x
  end interface bar
  procedure(sub) :: x
  interface
    integer function sub()
    end function sub
  end interface
end module modproc

integer function x()
  implicit none
  x = -5
end function x

program test_fortran
  use modproc
  implicit none
  if (x() /= -5) then
    print *, 'Test failed: x() does not return -5'
    call abort()
  else
    print *, 'Test passed: x() returns -5'
  end if
end program test_fortran