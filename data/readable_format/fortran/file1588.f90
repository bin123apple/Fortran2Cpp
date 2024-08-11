program test
    call DD(TT)
contains
    subroutine DD(F)
        interface
            subroutine F(x)
                real :: x
            end subroutine F
        end interface
        call F(5.0) ! Passing a test value
    end subroutine DD

    subroutine TT(x)
        real :: x
        print *, 'TT called with X = ', x
    end subroutine
end program test