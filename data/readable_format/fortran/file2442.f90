program test_foo
  implicit none
  integer(kind=4) :: z

  ! Call the subroutine with an integer of kind=4
  call foo(z)
  print *, "Test passed: foo(z) executed successfully"

contains
  subroutine foo(a)
    type(*), dimension(..), contiguous :: a
    integer(kind=4) :: i
    if (sizeof(a) /= sizeof(i)) then
      print *, "Test failed: size mismatch"
      stop 1
    end if
  end subroutine foo
end program test_foo