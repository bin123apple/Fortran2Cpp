! great.f90
subroutine great(a, b)
    implicit none
    integer, intent(in) :: a, b
    
    if (a > b) then
        print *, a, 'is greater than', b
    else
        print *, a, 'is not greater than', b
    endif
end subroutine great

! Test
program testGreat
    implicit none
    call great(5, 3)
    call great(2, 4)
end program testGreat