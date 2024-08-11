module p
  implicit none

contains

  subroutine test()
    implicit none
    print *, avg(erfc)
  end subroutine test

  function avg(f) result(res)
    implicit none
    interface
      double precision function f(x)
        double precision, intent(in) :: x
      end function f
    end interface
    double precision :: res
    res = (f(1.0D0) + f(2.0D0)) / 2.0D0
  end function avg

  function erfc(x) result(res)
    double precision, intent(in) :: x
    double precision :: res
    res = x  ! Simplified for demonstration purposes
  end function erfc

end module p

program testProgram
  use p
  call test
end program testProgram