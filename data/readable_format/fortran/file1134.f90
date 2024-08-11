program test_parallel_fortran
    implicit none
    integer :: u(1024), v(1024), w(1024)
    integer :: i
    
    ! Initialize arrays
    do i = 1, 1024
        v(i) = i
        w(i) = 2*i
    end do
    
    ! Call the computation subroutine
    call compute(u, v, w)
    
    ! Test results
    do i = 1, 1024
        if (u(i) /= 3*i) then
            print *, "Test failed at index:", i
            stop
        endif
    end do
    print *, "Fortran test passed."
end program test_parallel_fortran

subroutine compute(u, v, w)
    integer, intent(out) :: u(1024)
    integer, intent(in) :: v(1024), w(1024)
    integer :: i
    
    ! Compute u = v + w
    !$omp parallel do
    do i = 1, 1024
        u(i) = v(i) + w(i)
    end do
end subroutine compute