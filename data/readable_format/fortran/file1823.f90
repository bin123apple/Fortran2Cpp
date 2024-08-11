! Define the selci_mxma subroutine
subroutine selci_mxma(a,iac,iar, b,ibc,ibr, c,icc,icr, nar,nac,nbc)
    implicit none
    ! Declare arguments and local variables
    real*8, intent(in) :: a(*), b(*)
    real*8, intent(out) :: c(*)
    integer, intent(in) :: iac, iar, ibc, ibr, icc, icr, nar, nac, nbc
    real*8 zero, bkj
    integer i, j, k, ij, i1j, k1j, i1k, kj, ik
    parameter (zero=0d0)

    ! Initialize matrix C
    i1j=1
    do 200 j=1,nbc
        ij=i1j
        do 100 i=1,nar
            c(ij)=zero
            ij=ij+icc
100     continue
        i1j=i1j+icr
200  continue

    ! Perform matrix multiplication
    i1j=1
    k1j=1
    do 500 j=1,nbc
        i1k=1
        kj=k1j
        do 400 k=1,nac
            bkj=b(kj)
            if(bkj.ne.zero) then
                ij=i1j
                ik=i1k
                do 300 i=1,nar
                    c(ij)=c(ij)+a(ik)*bkj
                    ij=ij+icc
                    ik=ik+iac
300             continue
            endif
            kj=kj+ibc
            i1k=i1k+iar
400     continue
        i1j=i1j+icr
        k1j=k1j+ibr
500  continue
end subroutine selci_mxma

! Main program to test the selci_mxma subroutine
program test_mxma
    implicit none
    real*8, dimension(4) :: a = [1d0, 2d0, 3d0, 4d0] ! Matrix A (2x2)
    real*8, dimension(4) :: b = [5d0, 6d0, 7d0, 8d0] ! Matrix B (2x2)
    real*8, dimension(4) :: c ! Matrix C (2x2) - result
    integer :: iac, iar, ibc, ibr, icc, icr
    integer :: nar, nac, nbc

    ! Initialize parameters for the subroutine
    c = 0d0
    iac = 1
    iar = 2
    ibc = 1
    ibr = 2
    icc = 1
    icr = 2
    nar = 2
    nac = 2
    nbc = 2

    ! Call the selci_mxma subroutine
    call selci_mxma(a, iac, iar, b, ibc, ibr, c, icc, icr, nar, nac, nbc)

    ! Print the resulting matrix C
    print *, "Resulting matrix C:"
    print *, c(1), c(2)
    print *, c(3), c(4)
end program test_mxma