program test_msolve
    implicit none
    integer, parameter :: n = 5
    real*8 :: r(n), z(n), rwork(n)
    integer :: i

    ! Initialize test data
    r = (/1.0d0, 2.0d0, 3.0d0, 4.0d0, 5.0d0/)
    rwork = (/1.0d0, 0.5d0, 2.0d0, 1.5d0, 1.0d0/)

    ! Expected output: z = r * rwork
    call msolve(n, r, z, 0, 0, 0, 0, 0, rwork, 0)

    ! Check results
    do i = 1, n
        if (z(i) /= r(i) * rwork(i)) then
            print *, "Test failed at index: ", i
            print *, "Expected: ", r(i) * rwork(i), " Got: ", z(i)
            stop
        endif
    enddo

    print *, "Fortran test passed."

end program test_msolve

subroutine msolve(n, r, z, nelt, ia, ja, a, isym, rwork, iwork)
    implicit none
    integer n, nelt, ia(*), ja(*), isym, iwork(*), i, nd
    real*8 r(*), z(*), a(*), rwork(*)

    do i = 1, n
        z(i) = r(i) * rwork(i)
    enddo

    return
end subroutine msolve