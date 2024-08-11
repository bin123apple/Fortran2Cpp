program test_program
  use m1
  implicit none

contains
  integer function w()
    w = 1
  end function w

  integer function x()
    x = 1
  end function x

  integer function y()
    y = 1
  end function y

  integer function z()
    z = 1
  end function z

  subroutine test_s1()
    print *, 'Testing s1 with function w'
    call s1(w)
    print *, 'Testing s1 with function x'
    call s1(x)
    print *, 'Testing s1 with function y'
    call s1(y)
    print *, 'Testing s1 with function z'
    call s1(z)
    print *, 'All s1 tests passed.'
  end subroutine test_s1

  subroutine test_s2()
    print *, 'Testing s2 with x()'
    call s2(x())
    print *, 's2 test passed.'
  end subroutine test_s2

  subroutine run_tests()
    call test_s1()
    call test_s2()
  end subroutine run_tests

end program test_program

module m1
contains
  subroutine s1(f)
    interface
      function f()
        integer f
      end function f
    end interface
    ! This subroutine now correctly interfaces with a function
  end subroutine s1

  subroutine s2(x)
    integer :: x
    ! This subroutine is correctly defined within the module
  end subroutine s2
end module m1