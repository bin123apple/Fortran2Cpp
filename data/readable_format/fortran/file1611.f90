program test_adfldp
    implicit none
    integer, parameter :: ndof = 2, nen = 3, numfn = 2
    integer, parameter :: izero = 0
    double precision :: dl(ndof, nen)
    integer :: lmf(nen)
    double precision :: dfault(ndof, numfn)
    integer :: i, j

    ! Test 1: All elements in lmf are different from izero
    print *, 'Test 1 setup:'
    dl = 0.0
    dfault = reshape((/1.0, 2.0, 3.0, 4.0/), shape(dfault))
    lmf = (/1, 2, 1/)
    call adfldp(dl, lmf, dfault, nen, numfn)
    print *, 'dl after Test 1:', dl

    ! Test 2: All elements in lmf are equal to izero
    print *, 'Test 2 setup:'
    dl = 0.0
    lmf = (/izero, izero, izero/)
    call adfldp(dl, lmf, dfault, nen, numfn)
    print *, 'dl after Test 2:', dl

    ! Test 3: Mixed case
    print *, 'Test 3 setup:'
    dl = 0.0
    lmf = (/1, izero, 2/)
    call adfldp(dl, lmf, dfault, nen, numfn)
    print *, 'dl after Test 3:', dl

contains

    subroutine adfldp(dl, lmf, dfault, nen, numfn)
        integer, intent(in) :: nen, numfn
        integer, intent(in) :: lmf(nen)
        double precision, intent(inout) :: dl(ndof, nen)
        double precision, intent(in) :: dfault(ndof, numfn)
        integer :: i, j, l

        do i = 1, nen
            if (lmf(i) /= izero) then
                l = lmf(i)
                do j = 1, ndof
                    dl(j, i) = dl(j, i) + dfault(j, l)
                end do
            end if
        end do
    end subroutine adfldp

end program test_adfldp