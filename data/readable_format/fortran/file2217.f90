program test_ai
    implicit none
    double precision, dimension(-1:4) :: a
    integer :: i

    ! Initialize array with some values
    do i = -1, 4
        a(i) = i * 1.0
    end do

    ! Call the subroutine
    call ai(a)

    ! Print the array to verify the subroutine call
    do i = -1, 4
        print *, 'a(', i, ') = ', a(i)
    end do
end program test_ai

subroutine ai(a)
    double precision, dimension(-1:*) :: a
    ! This subroutine currently does not modify the array, it's a placeholder.
    return
end subroutine ai