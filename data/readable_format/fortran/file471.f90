module foo
contains
  function bar(arg) result(res)
    integer :: arg
    integer :: res(3)
    res = [arg, arg+1, arg+2]
  end function bar
end module foo

program testFoo
  use foo
  implicit none
  integer :: a(3)
  integer :: i
  real :: d(3,3)
  integer :: x(2)
  integer :: shape_d(2)
  
  ! Test the bar function
  a = bar(5)
  do i = 1, 3
    if (a(i) /= 5 + i - 1) then
      print *, "Test failed for bar function with value ", a(i), " expected ", 5+i-1
      stop
    end if
  end do
  
  ! Demonstrate usage similar to original program
  shape_d = shape(d)
  print *, "Shape of d:", shape_d(1), shape_d(2)
  
  x = [1, 2]
  print *, "Array x:", x(1), x(2)
  
  a = bar(5)
  print *, "Result of bar(5):", a(1), a(2), a(3)
  
  print *, "All tests and demonstrations passed"
end program testFoo