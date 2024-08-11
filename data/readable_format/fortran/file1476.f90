! main.f90
program main
    integer :: a
    a = 1
    call test_a(a)
contains
    subroutine test_a(a)
        integer, intent(in) :: a
        if (a == 1) then
            print *, "Test passed."
        else
            print *, "Test failed."
        endif
    end subroutine test_a
end program main