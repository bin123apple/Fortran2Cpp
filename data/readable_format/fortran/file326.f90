program main
  implicit none
  
  ! Declaration of variables for testing subroutines and functions
  character(len=80) :: arg1
  character(len=80), dimension(2) :: arg2
  integer, dimension(4) :: arg3
  integer :: arg4
  character(len=4) :: arg5
  integer, dimension(2, 2) :: a, result_f1, result_e1
  character(len=80), dimension(3) :: slist
  character(len=32) :: tempString
  
  ! Test for subroutine bar
  arg1 = "Test for bar"
  arg2 = ["Array element 1                       ", "Array element 2                       "]
  arg3 = [1, 2, 3, 4]
  arg4 = 4
  arg5 = "abcd"
  call bar(arg1, arg2, arg3, arg4, arg5)
  
  ! Test for subroutine foo1
  slist = ["String 1                            ", "String 2                            ", "String 3                            "]
  call foo1(slist, 2)
  print *, "Modified slist(2):", trim(slist(2))
  
  ! Test for function f1 and entry point e1
  a = reshape([1, 2, 3, 4], [2, 2])
  result_f1 = f1(a)
  print *, "result_f1:"
  print *, result_f1
  
  result_e1 = e1(a)
  print *, "result_e1:"
  print *, result_e1

contains
  
  subroutine bar(arg1, arg2, arg3, arg4, arg5)
    character(len=*), intent(in) :: arg1
    character(len=*), dimension(:), intent(in) :: arg2
    integer, dimension(:), intent(in) :: arg3
    integer, intent(in) :: arg4
    character(len=*), intent(in) :: arg5
    print *, "arg1:", arg1
    print *, "arg2:", arg2
    print *, "arg3:", arg3
    print *, "arg4:", arg4
    print *, "arg5:", arg5
  end subroutine bar

  subroutine foo1(slist, i)
    character(len=*), dimension(:), intent(inout) :: slist
    integer, intent(in) :: i
    write(tempString, '(A,I0)') "hi=", i
    slist(i) = tempString
  end subroutine foo1
  
  function f1(a) result(res)
    integer, dimension(2, 2), intent(in) :: a
    integer, dimension(2, 2) :: res
    res = a + 15
  end function f1
  
  function e1(b) result(res)
    integer, dimension(2, 2), intent(in) :: b
    integer, dimension(2, 2) :: res
    res = b + 42
  end function e1

end program main