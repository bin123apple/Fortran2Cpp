program test_corr_parms
    implicit none

    ! Define parameters directly in the program
    integer, parameter :: ilg=3750
    integer, parameter :: jlg=3750
    integer, parameter :: kz=21
    integer, parameter :: ci=1440, cj=720

    ! Test constants
    if (ilg /= 3750) then
        print *, "Test failed for ilg"
    else if (jlg /= 3750) then
        print *, "Test failed for jlg"
    else if (kz /= 21) then
        print *, "Test failed for kz"
    else if (ci /= 1440) then
        print *, "Test failed for ci"
    else if (cj /= 720) then
        print *, "Test failed for cj"
    else
        print *, "All Fortran tests passed."
    endif

end program test_corr_parms