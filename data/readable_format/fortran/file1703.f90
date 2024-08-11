program test_sro
    implicit none
    integer, parameter :: n = 5
    integer :: ip(n) = (/1, 2, 3, 4, 5/)
    integer :: ia(n+1) = (/1, 2, 3, 4, 5, 6/)
    integer :: ja(n) = (/1, 2, 3, 4, 5/)
    double precision :: a(n) = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    integer :: q(n), r(n)
    logical :: dflag
    integer :: i

    dflag = .true.
    call sro(n, ip, ia, ja, a, q, r, dflag)

    print *, 'q:', q
    print *, 'r:', r
    print *, 'ia:', ia
    print *, 'ja:', ja
    print *, 'a:', a
end program test_sro

subroutine sro(n, ip, ia, ja, a, q, r, dflag)
    integer, intent(in) :: n
    integer, intent(inout) :: ip(*), ia(*), ja(*), q(*), r(*)
    double precision, intent(inout) :: a(*)
    logical, intent(in) :: dflag
    integer :: i, j, jmin, jmax, k, ilast, jdummy
    double precision :: ak

    do i = 1, n
        q(i) = 0
    end do

    do i = 1, n
        jmin = ia(i)
        jmax = ia(i+1) - 1
        if (jmin > jmax) cycle
        do j = jmin, jmax
            k = ja(j)
            if (ip(k) < ip(i)) then
                ja(j) = i
            end if
            if (ip(k) >= ip(i)) then
                k = i
            end if
            r(j) = k
            q(k) = q(k) + 1
        end do
    end do

    do i = 1, n
        ia(i+1) = ia(i) + q(i)
        q(i) = ia(i+1)
    end do

    ilast = 0
    jmin = ia(1)
    jmax = ia(n+1) - 1
    j = jmax
    do while (j >= jmin)
        i = r(j)
        if (.not.dflag .or. ja(j) /= i .or. i == ilast) then
            q(i) = q(i) - 1
            r(j) = q(i)
        else
            r(j) = ia(i)
            ilast = i
        end if
        j = j - 1
    end do

    do j = jmin, jmax
        do while (r(j) /= j)
            k = r(j)
            r(j) = r(k)
            r(k) = k
            jak = ja(k)
            ja(k) = ja(j)
            ja(j) = jak
            ak = a(k)
            a(k) = a(j)
            a(j) = ak
        end do
    end do
end subroutine sro