program main
    implicit none
    integer :: i
    i = 0
    call one(i)
    print *, "Value of i after one: ", i
end program main

subroutine one(i)
    implicit none
    integer, intent(inout) :: i
    i = i + 1
end subroutine one