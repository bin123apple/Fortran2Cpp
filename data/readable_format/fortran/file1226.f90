program valueTests
  implicit none
  integer :: myInt

  myInt = 10
  call mySub(myInt)
  call test_myInt_unchanged(myInt)
contains

  subroutine mySub(myInt)
    integer, value :: myInt
    myInt = 11
  end subroutine mySub

  subroutine test_myInt_unchanged(myInt)
    integer, intent(in) :: myInt
    if (myInt /= 10) then
      print *, "Test failed: myInt was modified."
    else
      print *, "Test passed: myInt remains unchanged."
    endif
  end subroutine test_myInt_unchanged

end program valueTests