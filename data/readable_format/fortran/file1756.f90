! foo_module.f90
module foo_mod
  implicit none
contains

  subroutine foo(x)
    integer, intent(in) :: x(:)
    integer :: sum, i
    sum = 0
    do i = 1, size(x)
       sum = sum + x(i)
    end do
    print *, 'Sum = ', sum
  end subroutine foo

end module foo_mod

! testfoo.f90
program testfoo
  use foo_mod
  implicit none
  integer, allocatable :: testArray(:)

  allocate(testArray(5))
  testArray = (/1, 2, 3, 4, 5/)
  call foo(testArray)
  deallocate(testArray)
end program testfoo