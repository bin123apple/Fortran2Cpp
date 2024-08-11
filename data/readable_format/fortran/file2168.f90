program main_fortran
    implicit none
    character(len=6) :: d(6)
    integer :: i

    d = ['1     ', 'hElLo ', 'W     ', 'orld  ', ' !    ', '      ']

    do i = size(d), 1, -1
        print *, trim(d(i))
    end do
end program main_fortran