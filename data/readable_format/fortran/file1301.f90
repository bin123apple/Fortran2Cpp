module triloc_module
    implicit none
contains
    function triloc(xp, yp, x, y, v, e, numtri) result(t)
        implicit none
        integer, intent(in) :: v(3,*), e(3,*), numtri
        real*8, intent(in) :: x(*), y(*), xp, yp
        integer :: t, v1, v2, i

        t = numtri
10      continue
        do i = 1, 3
            v1 = v(i, t)
            v2 = v(mod(i, 3) + 1, t)
            if ((y(v1) - yp) * (x(v2) - xp) > (x(v1) - xp) * (y(v2) - yp)) then
                t = e(i, t)
                goto 10
            endif
        end do
    end function triloc
end module triloc_module

program test_triloc
    use triloc_module
    implicit none
    integer, parameter :: numtri = 1
    integer :: v(3,numtri), e(3,numtri), result, expected_result
    real*8 :: x(3), y(3), xp, yp

    ! Initialize triangle vertices
    x = (/0.0, 10.0, 5.0/)
    y = (/0.0, 0.0, 10.0/)

    ! Initialize triangle vertex indices
    v(:, 1) = (/1, 2, 3/)

    ! Initialize triangle edges to point to themselves (no adjacency)
    e(:, 1) = (/1, 1, 1/)

    ! Test point inside the triangle
    xp = 5.0
    yp = 1.0
    expected_result = 1

    ! Call triloc function
    result = triloc(xp, yp, x, y, v, e, numtri)

    ! Check results
    if (result == expected_result) then
        print *, "Fortran Test Passed."
    else
        print *, "Fortran Test Failed."
    endif
end program test_triloc