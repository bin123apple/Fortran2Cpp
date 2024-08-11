program ft_test
  implicit none
  call test_ishft()
contains

  subroutine test_ishft()
    implicit none
    integer :: result

    result = ishft(1, -3)
    if (result == 0) then
      print *, "Test passed: 1 >> 3 = ", result
    else
      print *, "Test failed: 1 >> 3 != ", result
    end if
  end subroutine test_ishft

end program ft_test