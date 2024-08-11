program testFoo
  implicit none

  call testBar()

contains

  subroutine testBar()
    integer :: result

    result = bar(10)
    if (result == 10) then
      print *, "Test Passed: bar(10) = ", result
    else
      print *, "Test Failed: bar(10) ≠ 10, result = ", result
    end if
  end subroutine testBar

  pure function bar(a)
    integer, intent(in) :: a
    integer :: bar
    bar = a
  end function bar

end program testFoo