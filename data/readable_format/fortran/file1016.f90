module test
contains
  subroutine oacc1(result)
    implicit none
    integer :: i
    integer, intent(out) :: result
    integer, parameter :: n = 5
    integer :: a(n)
    result = 0

    !$acc data copyin(a) copyout(result)
    !$acc parallel loop reduction(+:result)
    do i = 1, n
        result = result + i
    end do
    !$acc end parallel loop
    !$acc end data
  end subroutine oacc1
end module test

program test_program
  use test
  implicit none
  integer :: result

  call oacc1(result)
  print *, "Result: ", result
end program test_program