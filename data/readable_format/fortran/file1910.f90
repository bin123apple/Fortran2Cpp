module ca
  implicit none
  real, allocatable :: a(:,:)
contains
  subroutine init
    allocate(a(10,10))
    a = 0.0  ! Initialize the array with zeros
  end subroutine init
end module ca

program bug068OKTest
  use ca
  implicit none
  call init
  
  a(3,2) = 5.0  ! Assign a value for testing
  a(5,6) = a(3,2)  ! Perform the operation from the original code
  
  ! Now test if the value at a(5,6) is as expected.
  if (a(5,6) == 5.0) then
    print *, "Test passed: a(5,6) == 5.0"
  else
    print *, "Test failed: a(5,6) != 5.0"
  end if
  
  ! Clean up
  deallocate(a)
end program bug068OKTest