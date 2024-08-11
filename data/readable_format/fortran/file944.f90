program check_program
    character(5) :: f = "(a)"
    call check_output
contains
    subroutine check_output
        print *, "check"
    end subroutine check_output
end program check_program