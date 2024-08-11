program main
    call test(1)
    call test(0)
contains
    subroutine test(n)
        integer, intent(in) :: n

        if (n == 1) then
            write(*, '(A)') 'yes'
        else
            write(*, '(A)') 'no'
        endif
    end subroutine test
end program