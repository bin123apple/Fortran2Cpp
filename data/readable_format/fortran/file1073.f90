program test_great_ne
    implicit none

    integer :: jj1 = 1, a1 = 2, bb1 = 3, y1 = 4, f1 = 5

    call great_ne(jj1, a1)
    call great_ne(bb1, y1)
    call great_ne(y1, f1)

    contains

    subroutine great_ne(var1, var2)
        integer, intent(in) :: var1, var2

        if (var1 /= var2) then
            print *, var1, " and ", var2, " are not equal."
        endif
    end subroutine great_ne

end program test_great_ne