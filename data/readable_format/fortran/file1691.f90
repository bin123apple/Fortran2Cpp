program where_13
    integer :: a(5)

    a = (/1, 2, 3, 4, 5/)
    where (a == 2)
        a = a * 2
    elsewhere
        a = a * 3
    endwhere

    print *, a
end program