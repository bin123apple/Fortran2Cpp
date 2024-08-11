module sire_functions
    implicit none
contains
    integer function sire_using_internal_blas()
        sire_using_internal_blas = 1
    end function sire_using_internal_blas

    integer function sire_using_internal_lapack()
        sire_using_internal_lapack = 1
    end function sire_using_internal_lapack

    integer function sire_using_internal_linpack()
        sire_using_internal_linpack = 1
    end function sire_using_internal_linpack
end module sire_functions

program test_sire
    use sire_functions
    implicit none
    integer :: result_blas, result_lapack, result_linpack

    ! Testing sire_using_internal_blas
    result_blas = sire_using_internal_blas()
    if (result_blas /= 1) then
        print *, "sire_using_internal_blas test failed"
    else
        print *, "sire_using_internal_blas test passed"
    end if

    ! Testing sire_using_internal_lapack
    result_lapack = sire_using_internal_lapack()
    if (result_lapack /= 1) then
        print *, "sire_using_internal_lapack test failed"
    else
        print *, "sire_using_internal_lapack test passed"
    end if

    ! Testing sire_using_internal_linpack
    result_linpack = sire_using_internal_linpack()
    if (result_linpack /= 1) then
        print *, "sire_using_internal_linpack test failed"
    else
        print *, "sire_using_internal_linpack test passed"
    end if

end program test_sire