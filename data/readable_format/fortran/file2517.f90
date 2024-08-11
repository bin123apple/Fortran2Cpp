module proc_pointer

  real :: a
  procedure(sub), pointer :: my_pointer

contains

  subroutine sub(x)
    real, intent(inout) :: x(:)
    integer :: i
    do i = 1, size(x)
       x(i) = 0.5**i
    end do
  end subroutine sub

end module proc_pointer

program test_proc_pointer
  use proc_pointer
  implicit none
  
  real :: test_array(3)
  integer :: i

  ! Initialize the test array
  test_array = [1.0, 2.0, 3.0]

  ! Assign the procedure pointer
  my_pointer => sub

  ! Call the subroutine via the procedure pointer
  call my_pointer(test_array)

  ! Print the results for verification
  print *, 'Test array after calling subroutine:'
  do i = 1, size(test_array)
     print *, test_array(i)
  end do

end program test_proc_pointer