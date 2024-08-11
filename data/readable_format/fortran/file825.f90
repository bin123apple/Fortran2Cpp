program test_p
  implicit none

  type :: t2345678901234567890123456789012345678901234567890123456789_123
     integer :: a2345678901234567890123456789012345678901234567890123456789_123
     integer :: b2345678901234567890123456789012345678901234567890123456789_123
  end type t2345678901234567890123456789012345678901234567890123456789_123

  type(t2345678901234567890123456789012345678901234567890123456789_123) :: instance
  integer :: status

  ! Initialize members
  instance%a2345678901234567890123456789012345678901234567890123456789_123 = 1
  instance%b2345678901234567890123456789012345678901234567890123456789_123 = 16

  ! Test member 'a'
  if (instance%a2345678901234567890123456789012345678901234567890123456789_123 == 1) then
    write(*,*) "Test passed: a234...123 initialization."
    status = 0
  else
    write(*,*) "Test failed: a234...123 did not initialize as expected."
    status = 1
  end if

  ! Test member 'b'
  if (instance%b2345678901234567890123456789012345678901234567890123456789_123 == 16) then
    write(*,*) "Test passed: b234...123 initialization."
  else
    write(*,*) "Test failed: b234...123 did not initialize as expected."
    status = 1
  end if

  if (status == 0) then
    write(*,*) "All tests passed."
  else
    write(*,*) "Some tests failed."
  end if

end program test_p