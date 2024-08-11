module magma_param
    implicit none
    integer, parameter :: sizeof_complex_16 = 16
    integer, parameter :: sizeof_complex    = 8
    integer, parameter :: sizeof_double     = 8
    integer, parameter :: sizeof_real       = 4
end module magma_param

program test_magma_param
    use magma_param
    implicit none

    ! Test sizeof_complex_16
    if (sizeof_complex_16 /= 16) then
        print *, "Test failed for sizeof_complex_16"
    else
        print *, "Test passed for sizeof_complex_16"
    endif

    ! Test sizeof_complex
    if (sizeof_complex /= 8) then
        print *, "Test failed for sizeof_complex"
    else
        print *, "Test passed for sizeof_complex"
    endif

    ! Test sizeof_double
    if (sizeof_double /= 8) then
        print *, "Test failed for sizeof_double"
    else
        print *, "Test passed for sizeof_double"
    endif

    ! Test sizeof_real
    if (sizeof_real /= 4) then
        print *, "Test failed for sizeof_real"
    else
        print *, "Test passed for sizeof_real"
    endif
end program test_magma_param