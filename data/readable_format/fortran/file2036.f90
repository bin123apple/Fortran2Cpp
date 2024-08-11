module selci_mxmb_mod
    implicit none
contains
    subroutine selci_mxmb(a, mcola, mrowa, b, mcolb, mrowb, r, mcolr, mrowr, ncol, nlink, nrow)
        implicit none
        double precision, dimension(:), intent(in) :: a, b
        double precision, dimension(:), intent(inout) :: r
        integer, intent(in) :: mcola, mrowa, mcolb, mrowb, mcolr, mrowr, ncol, nlink, nrow
        integer :: ir, ib, ibb, ia, irr, iaa, i, j, k
        double precision :: fac

        ir = 1
        ib = 1
        do j = 1, nrow
            ibb = ib
            ia = 1
            do k = 1, nlink
                fac = b(ibb)
                if (fac /= 0.0d0) then
                    irr = ir
                    iaa = ia
                    do i = 1, ncol
                        r(irr) = r(irr) + fac * a(iaa)
                        irr = irr + mcolr
                        iaa = iaa + mcola
                    end do
                end if
                ibb = ibb + mcolb
                ia = ia + mrowa
            end do
            ir = ir + mrowr
            ib = ib + mrowb
        end do
    end subroutine selci_mxmb
end module selci_mxmb_mod

program test_selci_mxmb
    use selci_mxmb_mod
    implicit none
    double precision, allocatable :: a(:), b(:), r(:)
    integer :: mcola, mrowa, mcolb, mrowb, mcolr, mrowr, ncol, nlink, nrow
    integer :: i

    ! Initialize matrices and parameters for the test
    ncol = 2
    nlink = 2
    nrow = 2
    allocate(a(ncol*nlink), b(nlink*nrow), r(ncol*nrow))
    a = (/1.0d0, 2.0d0, 3.0d0, 4.0d0/)
    b = (/2.0d0, 0.0d0, 1.0d0, 2.0d0/)
    r = (/0.0d0, 0.0d0, 0.0d0, 0.0d0/)

    mcola = 1
    mrowa = 2
    mcolb = 1
    mrowb = 2
    mcolr = 1
    mrowr = 2

    ! Call the subroutine
    call selci_mxmb(a, mcola, mrowa, b, mcolb, mrowb, r, mcolr, mrowr, ncol, nlink, nrow)

    ! Print the result
    print *, 'Result matrix R:'
    do i = 1, size(r)
        print *, r(i)
    end do
end program test_selci_mxmb