program test_fortran_code
    implicit none

    character*2 a
    character*4 b

    parameter (a="12")
    parameter (b = a)

    print *, 'a: ', a
    print *, 'b: ', b

end program test_fortran_code