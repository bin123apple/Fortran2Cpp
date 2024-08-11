program test
    implicit none
    call sub1
    call sub1
contains
    subroutine sub1
        integer, save :: a = 0
        a = a + 1
        print *, "Value of a:", a
    end subroutine
end program test