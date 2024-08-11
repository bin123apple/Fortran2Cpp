program test_where_5
    implicit none
    call where_5()
    print *, 'Fortran Test Passed'
end program test_where_5

subroutine where_5()
    integer, dimension(5) :: a
    real(kind=8), dimension(5) :: b

    a = (/1, 2, 3, 4, 5/)
    b = (/1d0, 0d0, 1d0, 0d0, 1d0/)
    
    where (b .ne. 0d0)
        a(:) = a(:) + 10
    endwhere
    if (any (a .ne. (/11, 2, 13, 4, 15/))) then
        print *, 'Fortran Test Failed'
        stop 1
    end if
    print *, 'Fortran Test Passed'
end subroutine where_5