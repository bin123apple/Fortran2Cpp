program main_test_program
    implicit none
    integer :: ie
    double precision :: val
    double precision, parameter :: expected(3) = (/1.2345678901234567D-04, &
                                                1.2345678901234567D00, &
                                                1.2345678901234567D04/)
    integer, parameter :: test_indices(3) = (/ -4, 0, 4 /)
    integer :: i

    do i = 1, 3
        ie = test_indices(i)
        val = 1.2345678901234567D0 * 10.D0**ie
        if (abs(val - expected(i)) > 1.0D-15) then
            print *, 'Test failed at ie =', ie
            stop
        endif
    end do

    print *, 'All tests passed.'
end program main_test_program