module a
contains
    subroutine b()
        print *, "Subroutine b called"
    end subroutine b
end module a

program test_a
    use a
    implicit none

    call b()
end program test_a