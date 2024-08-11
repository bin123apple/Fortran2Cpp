program main
    implicit none
    real, dimension(10) :: vector
    real, dimension(5)  :: subvector
    integer :: i

    ! Initialize the vector with some values
    do i = 1, 10
        vector(i) = real(i)
    end do

    ! Assign every other element to subvector
    subvector = vector(1:10:2)

    ! Print subvector to verify
    print *, 'Subvector: ', subvector

    ! Verify the correctness
    call verify_subvector(subvector)
end program main

subroutine verify_subvector(subvector)
    implicit none
    real, dimension(5), intent(in) :: subvector
    real, dimension(5) :: expected
    integer :: i

    ! Expected values in the subvector
    expected = (/ 1.0, 3.0, 5.0, 7.0, 9.0 /)

    ! Check each element
    do i = 1, 5
        if (subvector(i) /= expected(i)) then
            print *, 'Test failed: subvector(', i, ') = ', subvector(i), ' expected ', expected(i)
            stop
        end if
    end do

    print *, 'Test passed: subvector is correct'
end subroutine verify_subvector