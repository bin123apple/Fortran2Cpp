program test_q
    implicit none

contains

    subroutine qr(f)
        interface
            subroutine f(x)
                real, intent(in) :: x
            end subroutine
        end interface
        external f

        call f(5.0)
    end subroutine qr

    subroutine qc(f)
        interface
            subroutine f(x)
                complex, intent(in) :: x
            end subroutine
        end interface
        external f

        call f((5.0, 0.0))
    end subroutine qc

    subroutine realFunction(x)
        real, intent(in) :: x
        print *, 'Real function called with argument:', x
    end subroutine realFunction

    subroutine complexFunction(x)
        complex, intent(in) :: x
        print *, 'Complex function called with argument:', x
    end subroutine complexFunction

end program test_q

! Outside of 'program' but still in the same file, we call the subroutines
! This is incorrect for Fortran; subroutines to be called must be within a program or module scope.
! Demonstrating intent to call 'qr' and 'qc' with 'realFunction' and 'complexFunction'
! call qr(realFunction)
! call qc(complexFunction)