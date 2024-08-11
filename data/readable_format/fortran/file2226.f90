module parameter
    implicit none
    integer, parameter :: lx = 128
    integer, parameter :: ly = 128
    integer, parameter :: lz = 128
    integer, parameter :: lstep = 10
    integer, parameter :: lnpx = 2
    integer, parameter :: lnpy = 2
    integer, parameter :: lnpz = 2
    integer, parameter :: llx = lx / lnpx
    integer, parameter :: lly = ly / lnpy
    integer, parameter :: llz = lz / lnpz
end module parameter

program test_parameters
    use parameter
    implicit none

    ! Test code here
    print *, "lx = ", lx
    print *, "ly = ", ly
    print *, "lz = ", lz
    print *, "lstep = ", lstep
    print *, "lnpx = ", lnpx
    print *, "lnpy = ", lnpy
    print *, "lnpz = ", lnpz
    print *, "llx = ", llx
    print *, "lly = ", lly
    print *, "llz = ", llz

    call check_values()
    
contains

    subroutine check_values()
        if (lx /= 128) then
            print *, "Error in lx"
        endif
        if (ly /= 128) then
            print *, "Error in ly"
        endif
        if (lz /= 128) then
            print *, "Error in lz"
        endif
        if (lstep /= 10) then
            print *, "Error in lstep"
        endif
        if (lnpx /= 2) then
            print *, "Error in lnpx"
        endif
        if (lnpy /= 2) then
            print *, "Error in lnpy"
        endif
        if (lnpz /= 2) then
            print *, "Error in lnpz"
        endif
        if (llx /= 64) then
            print *, "Error in llx"
        endif
        if (lly /= 64) then
            print *, "Error in lly"
        endif
        if (llz /= 64) then
            print *, "Error in llz"
        endif

        print *, "All parameter checks passed."
    end subroutine check_values
end program test_parameters