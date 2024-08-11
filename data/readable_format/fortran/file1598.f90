! test_main.f90
program test_main
    implicit none
    integer, parameter :: n = 1024
    integer :: i
    integer, dimension(0:n-1) :: a, b, c
    logical :: test_passed

    ! Populate arrays
    do i = 0, n - 1
        a(i) = i * 2
        b(i) = i * 4
        c(i) = a(i) + b(i)
    end do

    ! Test
    test_passed = .true.
    do i = 0, n - 1
        if (a(i) /= i*2 .or. b(i) /= i*4 .or. c(i) /= i*6) then
            test_passed = .false.
            exit
        endif
    end do

    if (test_passed) then
        print *, "All tests passed."
    else
        print *, "Test failed."
    endif

end program test_main