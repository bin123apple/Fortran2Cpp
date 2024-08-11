program test
    implicit none
    integer, parameter :: n = 100
    real, pointer :: a(:), temp(:)
    integer :: i
    logical :: test_passed

    allocate(a(n), temp(n))
    
    ! Fill 'a' with test data
    do i = 1, n
        a(i) = real(i)
    end do

    ! Copy data
    temp(1:size(a)) = a

    ! Test
    test_passed = .true.
    do i = 1, n
        if (temp(i) /= a(i)) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif

end program