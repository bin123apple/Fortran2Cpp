program test_three_body
    implicit none
    integer, parameter ::  n = 2, d = 2
    real, dimension(n,d) :: x_hq
    integer :: i, j
    logical :: test_passed

    call step(x_hq)
    
    test_passed = .true.
    do i = 1, n
        do j = 1, d
            if (x_hq(i,j) /= 1.0) then
                test_passed = .false.
                exit
            endif
        end do
        if (.not. test_passed) exit
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif

contains

    subroutine step(x)
        real, dimension(:,:), intent(inout) :: x
        x = 1.0
    end subroutine step

end program test_three_body