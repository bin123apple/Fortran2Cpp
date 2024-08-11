subroutine test(block, array)
    integer, intent(inout) :: block(9)
    integer, intent(in) :: array(2)
    integer :: i, j

    do i = array(1), array(2), 2
        do j = array(1), array(2), 3
            block(i) = j
        end do
    end do
end subroutine test

program test_program
    implicit none
    integer :: block(9), array(2), i

    ! Initialize block array to zero
    block = 0
    array(1) = 1
    array(2) = 9

    call test(block, array)

    do i = 1, 9
        print *, 'block(', i, ') = ', block(i)
    end do
end program test_program