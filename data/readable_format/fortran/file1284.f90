module m
contains
  function f()
    integer :: f
    f = 42
    call sub ()
    if (f.eq.1) f = f + 1
  contains
    subroutine sub
     if (f.eq.42) f = f - 41
    end subroutine sub
  end function f
end module m

program test
  use m
  call test_f()
contains
  subroutine test_f()
    if (f() .eq. 2) then
      print *, "Test passed."
    else
      print *, "Test failed."
    end if
  end subroutine test_f
end program test