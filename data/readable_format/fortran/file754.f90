module test_funcs_mod
  implicit none
contains
  function test1(n)
    integer, intent(in) :: n
    character(n) :: test1
    test1 = ""
  end function test1

  function test2()
    character(1) :: test2
    test2 = ""
  end function test2

  function test3()
    character(1) :: test3
    test3 = ""  ! Fortran doesn't directly support character(*) for automatic length in function return. Adjusted for simplicity.
  end function test3

  function test4(n)
    integer, intent(in) :: n
    character(n) :: test4
    test4 = ""
  end function test4

  function test5()
    character(1) :: test5
    test5 = ""
  end function test5

  function test6()
    character(1) :: test6
    test6 = ""  ! Adjusted for simplicity, since character(*) in function return is tricky without a specific context.
  end function test6
end module test_funcs_mod

program test_fortran_functions
  use test_funcs_mod
  implicit none
  character(10) :: result1
  character(1) :: result2
  character(1) :: result3  ! Adjusted for simplicity
  character(10) :: result4
  character(1) :: result5
  character(1) :: result6  ! Adjusted for simplicity
  
  result1 = test1(10)
  print *, "Test1: ", result1
  
  result2 = test2()
  print *, "Test2: ", result2
  
  result3 = test3()
  print *, "Test3: ", result3
  
  result4 = test4(10)
  print *, "Test4: ", result4
  
  result5 = test5()
  print *, "Test5: ", result5
  
  result6 = test6()
  print *, "Test6: ", result6
end program test_fortran_functions