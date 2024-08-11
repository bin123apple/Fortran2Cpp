program pr56015_test
  implicit none
  complex*16 p(10)
  p(:) = (0.1d0, 0.2d0)
  p(:) = (0.0d0, 1.0d0) * p(:)
  call foo (p)
  call test_foo()
contains
  subroutine foo (p)
    complex*16 p(10)
    if (any (p .ne. (-0.2d0, 0.1d0))) call abort
  end subroutine

  subroutine test_foo
    complex*16 p_test(10), expected(10)
    p_test = (0.1d0, 0.2d0)
    p_test = (0.0d0, 1.0d0) * p_test
    expected = (-0.2d0, 0.1d0)

    if (all(p_test == expected)) then
      print *, "Test Passed!"
    else
      print *, "Test Failed!"
      call abort
    endif
  end subroutine
end program pr56015_test