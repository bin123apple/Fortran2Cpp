! Filename: test_foo_simplified.f90
module foo_module
contains
  subroutine foo (r)
    integer :: i, r
    !$omp parallel do reduction(+: r)
      do i = 1, 10
        r = r + 1
      end do
    !$omp end parallel do
  end subroutine foo
end module foo_module

program testFoo
  use foo_module
  implicit none
  integer :: result

  result = 0
  call foo(result)

  if (result == 10) then
    print *, "Test Passed: result = ", result
  else
    print *, "Test Failed: result = ", result
  endif
end program testFoo