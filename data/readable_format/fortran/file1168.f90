! fpchep.f90
program test_fpchep
    implicit none
    integer :: ier
    integer, parameter :: m = 5, n = 7, k = 2
    real :: x(m) = [1.0, 2.0, 3.0, 4.0, 5.0]
    real :: t(n) = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0]

    call fpchep(x, m, t, n, k, ier)
    
    print *, "Fortran Test Case 1: IER =", ier
    if (ier == 0) then
        print *, "PASS"
    else
        print *, "FAIL"
    end if
end program test_fpchep

subroutine fpchep(x, m, t, n, k, ier)
    implicit none
    integer, intent(in) :: m, n, k
    real, intent(in) :: x(m), t(n)
    integer, intent(out) :: ier
    integer :: i, j, k1, k2, nk1, nk2
    ier = 10
    
    k1 = k + 1
    k2 = k1 + 1
    nk1 = n - k1
    nk2 = nk1 + 1
    
    if (nk1 < k1 .or. n > m + 2 * k) return
    
    do i = 1, k
        if (t(i) > t(i+1)) return
    end do
    
    ier = 0
end subroutine fpchep