! Define the subroutine mafillpbc first
subroutine mafillpbc(nef,au,ad,jq,irow,b,iatleastonepressurebc,nzs)
    implicit none
    integer, intent(in) :: nef, jq(*), irow(*), iatleastonepressurebc, nzs
    real(kind=8), intent(inout) :: ad(*), au(*), b(*)
    integer :: i
    
    if (iatleastonepressurebc.eq.0) then
        ad(nef) = 1.d0
        b(nef) = 0.d0
        do i=2,nef
            if (jq(i)-1>0) then
                if (irow(jq(i)-1).eq.nef) then
                    au(jq(i)-1) = 0.d0
                endif
            endif
        enddo
    endif
end subroutine mafillpbc

! Main program for testing
program test_mafillpbc
    implicit none
    integer, parameter :: n = 5
    integer :: irow(n) = [1, 2, 3, 4, 5]
    integer :: jq(n) = [2, 3, 4, 5, 6]
    real(kind=8) :: ad(n) = [0.0d0, 0.0d0, 0.0d0, 0.0d0, 0.0d0]
    real(kind=8) :: au(n) = [0.0d0, 0.0d0, 0.0d0, 0.0d0, 0.0d0]
    real(kind=8) :: b(n) = [0.0d0, 0.0d0, 0.0d0, 0.0d0, 0.0d0]
    integer :: iatleastonepressurebc
    integer :: nzs
    
    ! Test case 1: iatleastonepressurebc = 0
    iatleastonepressurebc = 0
    call mafillpbc(n, au, ad, jq, irow, b, iatleastonepressurebc, nzs)
    print *, "Test case 1: iatleastonepressurebc = 0"
    print *, "ad(n): ", ad(n)
    print *, "b(n): ", b(n)
    print *, "au values modified: ", au
    
    ! Reset arrays for next test
    ad = 0.0d0
    b = 0.0d0
    au = 0.0d0
    
    ! Test case 2: iatleastonepressurebc = 1 (no changes expected)
    iatleastonepressurebc = 1
    call mafillpbc(n, au, ad, jq, irow, b, iatleastonepressurebc, nzs)
    print *, "Test case 2: iatleastonepressurebc = 1"
    print *, "ad(n): ", ad(n)
    print *, "b(n): ", b(n)
    print *, "au values modified: ", au
end program test_mafillpbc