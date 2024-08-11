program main
    real x
    x = 1.
    call func2()
    contains
        subroutine func2()
            character x
            x = 'A'
            print *, 'In func2, x should be A:', x
        end subroutine
end program