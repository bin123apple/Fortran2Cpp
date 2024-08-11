! Define the m_precision module
module m_precision
    implicit none
    integer, parameter :: kint = selected_int_kind(8) ! Example kind for 64-bit integers
end module m_precision

! Define the m_quad_2_triangle module
module m_quad_2_triangle
    use m_precision
    implicit none
    integer (kind=kint), parameter :: ie_quad_2_tri(3,2) &
        = reshape((/1, 2, 3, 1, 3, 4/), shape=(/3,2/))
end module m_quad_2_triangle

! Main program for testing
program test_m_quad_2_triangle
    use m_quad_2_triangle
    implicit none
    
    integer :: i, j
    integer, parameter :: expected_values(3,2) = reshape((/1, 2, 3, 1, 3, 4/), shape=(/3,2/))
    
    ! Loop through each element of the array and compare it with the expected value
    do i = 1, 3
        do j = 1, 2
            if (ie_quad_2_tri(i, j) /= expected_values(i, j)) then
                print *, "Test Failed: Element (", i, ",", j, ") =", ie_quad_2_tri(i, j), &
                          "Expected =", expected_values(i, j)
                stop
            end if
        end do
    end do
    
    ! If all elements match the expected values, print success message
    print *, "All tests passed."
end program test_m_quad_2_triangle