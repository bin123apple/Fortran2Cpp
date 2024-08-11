program test_jgroup
    implicit none
    integer, parameter :: n = 5, maxg = 5
    integer :: ia(n+1), ja(n*2), igp(maxg), jgp(n), incl(n), jdone(n), ngrp, ier
    integer :: i

    ! Initialize the ia, ja arrays, and others
    ia = (/ 1, 3, 5, 7, 9, 11 /)
    ja = (/ 1, 2, 1, 3, 2, 4, 3, 5, 4, 5 /)
    ngrp = 0
    ier = 0

    ! Call the jgroup subroutine
    call jgroup(n, ia, ja, maxg, ngrp, igp, jgp, incl, jdone, ier)

    ! Output results for verification
    print *, 'ier =', ier
    print *, 'ngrp =', ngrp
    print *, 'igp =', igp
    print *, 'jgp =', jgp

end program test_jgroup

! The jgroup subroutine definition starts here
subroutine jgroup (n,ia,ja,maxg,ngrp,igp,jgp,incl,jdone,ier)
    integer n, ia, ja, maxg, ngrp, igp, jgp, incl, jdone, ier
    dimension ia(1), ja(1), igp(1), jgp(n), incl(n), jdone(n)
    integer i, j, k, kmin, kmax, ncol, ng
    ier = 0
    do 10 j = 1,n
10     jdone(j) = 0
    ncol = 1
    do 60 ng = 1,maxg
        igp(ng) = ncol
        do 20 i = 1,n
20       incl(i) = 0
        do 50 j = 1,n
            if (jdone(j) .eq. 1) go to 50
            kmin = ia(j)
            kmax = ia(j+1) - 1
            do 30 k = kmin,kmax
                i = ja(k)
                if (incl(i) .eq. 1) go to 50
30             continue
            jgp(ncol) = j
            ncol = ncol + 1
            jdone(j) = 1
            do 40 k = kmin,kmax
                i = ja(k)
40             incl(i) = 1
50         continue
        if (ncol .eq. igp(ng)) go to 70
60   continue
    if (ncol .le. n) go to 80
    ng = maxg
70  ngrp = ng - 1
    return
80  ier = 1
    return
end subroutine jgroup