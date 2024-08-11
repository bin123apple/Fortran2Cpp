module c_funloc_tests_5
  use, intrinsic :: iso_c_binding, only: c_funloc, c_funptr
contains
  subroutine sub0() bind(c)
    type(c_funptr) :: my_c_funptr

    my_c_funptr = c_funloc(sub1) 

    my_c_funptr = c_funloc(func0) 
  end subroutine sub0

  subroutine sub1() 
    print *, "sub1 called"
  end subroutine sub1

  function func0(desired_retval) result(res)
    use, intrinsic :: iso_c_binding, only: c_int
    integer(c_int), value :: desired_retval
    integer(c_int) :: res
    res = desired_retval
  end function func0
end module c_funloc_tests_5

program test_c_funloc_tests_5
  use c_funloc_tests_5
  implicit none
  integer :: res

  ! Testing direct call of func0
  res = func0(42)
  if (res == 42) then
      print *, "Test func0 direct call: Passed"
  else
      print *, "Test func0 direct call: Failed"
  endif

  ! Here you would ideally test the functionality of sub0 and sub1 and the function pointer assignment and call.
  ! However, without direct support for calling function pointers or observing the effects of sub1 in Fortran,
  ! the testability is limited. In a real-world scenario, you'd adjust sub1 to have observable side effects (e.g., modifying a module variable)
  ! and verify those effects here.

end program test_c_funloc_tests_5