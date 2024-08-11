! SingleFileTest.f90
module B1
contains
  subroutine sub()
    integer :: x(1)
    character(len=:), allocatable :: st
    x(1) = 3  ! Example initialization, adjust as needed.
    st = fun(x)
    print *, 'st: ', st
  end subroutine sub

  function fun(x) result(st)
    integer, intent(in) :: x(1)
    character(len=lenf(x)) :: st
    st = 'abc'
  end function fun

  pure integer function lenf(x)
    integer, intent(in) :: x(1)
    lenf = x(1)
  end function lenf
end module B1

program TestB1
  use B1
  call sub()
end program TestB1