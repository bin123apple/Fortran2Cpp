program testFoo
  implicit none
  call foo(1)
  print *, 'Fortran test passed.'
end program testFoo

subroutine foo(ia1)
  integer :: ia1
  integer :: i1, i2
  ! The body of foo is empty.
end subroutine foo