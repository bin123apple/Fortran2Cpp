program test_interpol_alfa2
    implicit none
    real*8 lzd
    real*8 reynolds
    real*8 alfa2

    ! Test 1
    lzd = 0.0d0
    reynolds = 0.0d0
    call interpol_alfa2(lzd, reynolds, alfa2)
    if (alfa2 == 1.0d0) then
        print *, "Test 1 passed."
    else
        print *, "Test 1 failed."
    endif

contains

    subroutine interpol_alfa2(lzd, reynolds, alfa2)
        implicit none
        real*8 alfa2, lzd, reynolds
        alfa2 = 1.d0
    end subroutine interpol_alfa2

end program test_interpol_alfa2