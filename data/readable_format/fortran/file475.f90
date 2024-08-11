module test
contains
  subroutine oacc1(a, size)
    implicit none
    integer, intent(inout) :: a(*)
    integer, value :: size
    integer :: i
    !$acc parallel loop
    do i = 1, size
      a(i) = a(i) + 1
    end do
    !$acc end parallel loop
  end subroutine oacc1
end module test

program test_program
  use test
  integer, allocatable :: a(:)
  integer :: i, size
  
  size = 5
  allocate(a(size))
  a = 0
  
  call oacc1(a, size)
  
  do i = 1, size
    print *, "a(", i, ") = ", a(i)
  end do
  
  deallocate(a)
end program test_program