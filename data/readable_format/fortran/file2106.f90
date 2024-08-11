program test
    implicit none
    integer :: c(100)
    c(1) = 1
    call suba(c)
    ! Adding a simple check instead of a full unit test
    if (c(1) == 1) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif
end program test

subroutine suba(c)
    integer, intent(in) :: c(*)
    print *, "suba output:", c(1)
end subroutine suba