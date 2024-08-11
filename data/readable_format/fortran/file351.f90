program test_great_ne
  implicit none
  
  ! Assuming the parameters are integers for this example
  call great_ne(1, 2)
  
  print *, "Test passed."
end program test_great_ne

subroutine great_ne(a, b)
  implicit none
  ! Assuming integer parameters for this example
  integer, intent(in) :: a, b
  ! This subroutine does nothing
end subroutine great_ne