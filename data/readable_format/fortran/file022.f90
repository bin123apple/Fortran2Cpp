program test_functions
  implicit none

  ! Declare variables necessary for tests
  integer :: n
  character(len=5) :: result1
  character(len=1) :: result2
  character(len=5) :: result4
  character(len=1) :: result5

  ! Test function calls
  n = 5
  result1 = test1(n)
  print *, 'Test1: ', result1

  result2 = test2()
  print *, 'Test2: ', result2

  result4 = test4(n)
  print *, 'Test4: ', result4

  result5 = test5()
  print *, 'Test5: ', result5

contains

  function test1(n) result(res)
    integer, intent(in) :: n
    character(len=n) :: res
    res = "     "
  end function test1

  function test2() result(res)
    character(1) :: res
    res = " "
  end function test2

  function test4(n) result(res)
    integer, intent(in) :: n
    character(len=n) :: res
    res = "     "
  end function test4

  function test5() result(res)
    character(1) :: res
    res = " "
  end function test5

end program test_functions