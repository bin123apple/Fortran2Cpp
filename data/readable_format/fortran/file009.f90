! test.f90
subroutine test(block, array)
    implicit none
    integer, intent(inout) :: block(9)
    integer, intent(in) :: array(2)
    integer :: i

    do i = array(1), array(2), 2
        block(i) = i
    end do

    do i = array(2), array(1), -2
        block(i) = block(i) + i
    end do
end subroutine test

program main
    implicit none
    integer :: block(9), array(2), i

    ! Test Case 1
    block = 0
    array = [1, 8]
    call test(block, array)
    print *, 'Test Case 1 Results:'
    do i = 1, 9
        print *, 'block(', i, ') = ', block(i)
    end do

    ! Test Case 2
    block = 0
    array = [2, 9]
    call test(block, array)
    print *, 'Test Case 2 Results:'
    do i = 1, 9
        print *, 'block(', i, ') = ', block(i)
    end do
end program main