program test_fortran
    implicit none
    character(len=3) :: a, yes='no'
    open (56, status='new', file='tmpfile', pad=yes)
    inquire (56, pad=a)
    print *, 'Fortran: Pad:', a
    close (56, status='delete')
end program test_fortran