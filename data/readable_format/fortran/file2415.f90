program test_main
    implicit none
    integer :: test_status

    call run_tests(test_status)
    if (test_status /= 0) then
        print *, "Test failed with status ", test_status
    else
        print *, "All tests passed successfully."
    end if
end program test_main

subroutine run_tests(test_status)
    implicit none
    integer, intent(out) :: test_status
    integer :: main_status

    ! Call the main program subroutine and capture its exit status
    call main(main_status)

    if (main_status /= 0) then
        test_status = 1
    else
        test_status = 0
    end if
end subroutine run_tests

subroutine main(status)
    implicit none
    integer, intent(out) :: status
    integer:: i
    integer, parameter:: N = 10
    character(20) :: buffer
    character(len=:), allocatable :: ca(:)
    allocate(character(len=N) :: ca(3))
    ca(1) = "foo"
    ca(2) = "bar"
    ca(3) = "xyzzy"
    write (buffer, '(3A5)') ca(1:3)
    if (trim(buffer) .ne. "foo  bar  xyzzy") then
        status = 1
    else
        status = 0
    end if
end subroutine main