program test
  implicit none
  call test_f_no_arg()
  call test_f_with_arg()

contains

  subroutine test_f_no_arg()
    character(7) :: result
    result = f()
    if (result == 'absent') then
      print *, 'Test with no arg: PASS'
    else
      print *, 'Test with no arg: FAIL'
    end if
  end subroutine test_f_no_arg

  subroutine test_f_with_arg()
    character(7) :: result
    result = f(1)
    if (result == 'present') then
      print *, 'Test with arg: PASS'
    else
      print *, 'Test with arg: FAIL'
    end if
  end subroutine test_f_with_arg

  character(7) function f(i)
    integer, optional :: i
    if (present(i)) then
      f = 'present'
    else
      f = 'absent'
    endif
  end function f

end program test