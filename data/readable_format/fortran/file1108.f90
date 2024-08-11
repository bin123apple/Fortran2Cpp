module mod
    integer :: i = 42
contains
    subroutine print_i()
        print *, i
    end subroutine print_i
end module mod

program test
    use mod
    call print_i()
end program test