program test_great_ne
    implicit none

    ! External subroutine declaration
    external :: great_ne

    ! Test calls
    call great_ne(1, 2)
    call great_ne(3, 3)
    call great_ne(4, 5)
    call great_ne(6, 6)
    call great_ne(7, 8)

end program test_great_ne

subroutine great_ne(a, b)
    integer, intent(in) :: a, b
    if (a /= b) then
        print *, "great_ne: ", a, "and", b, "are not equal."
    else
        print *, "great_ne: ", a, "and", b, "are equal."
    endif
end subroutine great_ne