program test_save_2
  implicit none
  integer :: i, result

  ! Function declarations
  interface
     integer function foo1()
     end function foo1
     integer function foo2()
     end function foo2
     integer function foo3()
     end function foo3
     integer function foo4()
     end function foo4
  end interface

  do i = 1, 10
     result = foo1()
     if (result /= i) then
        print *, 'Test failed for foo1 at i =', i
        stop 1
     end if

     result = foo2()
     if (result /= i) then
        print *, 'Test failed for foo2 at i =', i
        stop 2
     end if

     result = foo3()
     if (result /= i) then
        print *, 'Test failed for foo3 at i =', i
        stop 3
     end if

     result = foo4()
     if (result /= i) then
        print *, 'Test failed for foo4 at i =', i
        stop 4
     end if
  end do

  print *, 'All tests passed successfully.'

end program test_save_2

! Function definitions
integer function foo1()
  integer :: j
  save
  data j /0/
  j = j + 1
  foo1 = j
end function foo1

integer function foo2()
  integer :: j
  save j
  data j /0/
  j = j + 1
  foo2 = j
end function foo2

integer function foo3()
  integer :: j
  save
  data j /0/
  j = j + 1
  foo3 = j
end function foo3

integer function foo4()
  integer :: j
  save j
  data j /0/
  j = j + 1
  foo4 = j
end function foo4