module data_mod
    implicit none
    integer, parameter :: n = 1024
    integer, dimension(0:n-1) :: a, b, c
end module data_mod

program main
    use data_mod
    implicit none
    integer :: i

    !$acc data copyout(a)
    !$acc kernels present(a)
    do i = 0, n - 1
        a(i) = i * 2
    end do
    !$acc end kernels
    !$acc end data

    !$acc data copyout(b)
    !$acc kernels present(b)
    do i = 0, n - 1
        b(i) = i * 4
    end do
    !$acc end kernels
    !$acc end data

    !$acc data copyin(a, b) copyout(c)
    !$acc kernels present(a, b, c)
    do i = 0, n - 1
        c(i) = a(i) + b(i)
    end do
    !$acc end kernels
    !$acc end data

    call unit_test()

contains

    subroutine unit_test()
        use data_mod
        implicit none
        integer :: i
        logical :: test_passed
        
        test_passed = .true.
        
        do i = 0, n - 1
            if (a(i) /= i * 2) then
                print *, 'Test failed for array a at index:', i
                test_passed = .false.
            endif
            if (b(i) /= i * 4) then
                print *, 'Test failed for array b at index:', i
                test_passed = .false.
            endif
            if (c(i) /= a(i) + b(i)) then
                print *, 'Test failed for array c at index:', i
                test_passed = .false.
            endif
        end do
        
        if (test_passed) then
            print *, 'All tests passed.'
        else
            print *, 'Some tests failed.'
        endif
    end subroutine unit_test

end program main