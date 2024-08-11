! great_ne.f90
    program test_great_ne
        implicit none

        call great_ne(5, 3)
        call great_ne(2, 4)
        call great_ne(7, 7)

    contains
        
        subroutine great_ne(a, b)
            integer, intent(in) :: a, b
            
            if (a > b) then
                print *, a, "is greater than", b
            else
                print *, a, "is not greater than", b
            end if
        end subroutine great_ne

    end program test_great_ne