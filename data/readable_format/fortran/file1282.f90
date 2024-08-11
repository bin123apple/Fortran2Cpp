program test_conjg
    implicit none
    complex :: z
    complex(KIND=8) :: dz
    z = (2.0, 3.0)
    dz = (2.71_8, -3.14_8)
    z = conjg(z)
    dz = conjg(dz)
    ! Check results
    if (z == cmplx(2.0, -3.0) .and. dz == cmplx(2.71_8, 3.14_8)) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program test_conjg