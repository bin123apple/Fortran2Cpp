module test
contains
  subroutine oacc1(result)
    implicit none
    integer, intent(out) :: result
    integer :: i
    integer, parameter :: n = 5
    integer :: a

    a = 1
    result = 0

    !$acc parallel loop reduction(+:result)
    do i = 1,n
      result = result + a
    enddo
    !$acc end parallel loop
  end subroutine oacc1
end module test

program main
  use test
  implicit none
  integer :: result

  call oacc1(result)

  print *, "Result of oacc1: ", result
end program main