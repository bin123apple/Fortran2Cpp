module sizes
    integer, parameter :: MAX_ATOMS = 1, &
                         MAX_ATM_RES = 10000,  &
                         MAX_CONNEXIONS = 1, &
                         MAX_DERIVED_CNX = 1
end module sizes

program test_sizes
    use sizes
    implicit none

    if (MAX_ATOMS /= 1) then
        print *, 'Test failed for MAX_ATOMS'
    else
        print *, 'Test passed for MAX_ATOMS'
    endif

    if (MAX_ATM_RES /= 10000) then
        print *, 'Test failed for MAX_ATM_RES'
    else
        print *, 'Test passed for MAX_ATM_RES'
    endif

    if (MAX_CONNEXIONS /= 1) then
        print *, 'Test failed for MAX_CONNEXIONS'
    else
        print *, 'Test passed for MAX_CONNEXIONS'
    endif

    if (MAX_DERIVED_CNX /= 1) then
        print *, 'Test failed for MAX_DERIVED_CNX'
    else
        print *, 'Test passed for MAX_DERIVED_CNX'
    endif

end program test_sizes