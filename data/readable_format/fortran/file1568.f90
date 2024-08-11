program test_hunt
    implicit none
    double precision, dimension(10) :: xx
    integer :: jlo, n
    double precision :: x

    ! Initialize test data
    xx = (/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0/)
    n = 10

    ! Test case 1: Element exists in array
    x = 3.5
    jlo = 0
    call hunt(xx, n, x, jlo)
    print *, "For x = 3.5, jlo should be around 3 or 4, jlo found:", jlo

    ! Test case 2: Element not in array (lower bound)
    x = 0.5
    jlo = 0
    call hunt(xx, n, x, jlo)
    print *, "For x = 0.5, jlo should be 1 (lower bound), jlo found:", jlo

    ! Test case 3: Element not in array (upper bound)
    x = 10.5
    jlo = 0
    call hunt(xx, n, x, jlo)
    print *, "For x = 10.5, jlo should be 10 (last index), jlo found:", jlo

end program test_hunt

subroutine hunt(xx, n, x, jlo)
    implicit none
    double precision, dimension(n) :: xx
    integer :: n, jlo
    double precision :: x
    integer :: jhi, jm, inc
    logical :: ascnd

    ascnd = xx(n) > xx(1)
    if (jlo < 1 .or. jlo > n) then
        jlo = 1
        jhi = n + 1
    else
        inc = 1
        if ((x >= xx(jlo)) .eqv. ascnd) then
            do
                jhi = jlo + inc
                if (jhi > n) then
                    jhi = n + 1
                    exit
                elseif ((x < xx(jhi)) .eqv. ascnd) then
                    exit
                else
                    jlo = jhi
                    inc = inc * 2
                endif
            end do
        else
            do
                jhi = jlo
                jlo = jhi - inc
                if (jlo < 1) then
                    jlo = 1
                    exit
                elseif ((x >= xx(jlo)) .eqv. ascnd) then
                    exit
                else
                    jhi = jlo
                    inc = inc * 2
                endif
            end do
        endif
    endif

    do while (jhi - jlo > 1)
        jm = (jhi + jlo) / 2
        if ((x >= xx(jm)) .eqv. ascnd) then
            jlo = jm
        else
            jhi = jm
        endif
    end do
end subroutine hunt