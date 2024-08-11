module overlap_mod
    implicit none
contains

function overlap(xa, xb, L2, n, atomlist, nlist) result(q)
    implicit none
    integer, intent(in) :: n, nlist, atomlist(nlist)
    double precision, intent(in) :: xa(3*n), xb(3*n), L2
    double precision :: dr2, q
    integer :: j1, j2, i1, i2
    q = 0.d0
    do j1=1,nlist
        i1 = (atomlist(j1)-1)*3
        do j2=1,nlist
            i2 = (atomlist(j2)-1)*3
            dr2 = sum( (xa(i1+1:i1+3) - xb(i2+1:i2+3))**2 )
            q = q + exp( -dr2 / L2 )
        end do
    end do
end function overlap

subroutine overlap_gradient(xa, xb, L2, n, atomlist, nlist, q, gradient)
    implicit none
    integer, intent(in) :: n, nlist, atomlist(nlist)
    double precision, intent(in) :: xa(3*n), xb(3*n), L2
    double precision, intent(out) :: q, gradient(3*n)
    double precision :: dr2, dr(3), q0, iL2
    integer :: j1, j2, i1, i2
    iL2 = 1.d0/L2
    q = 0.d0
    gradient(:) = 0.d0
    do j1=1,nlist
        i1 = (atomlist(j1)-1)*3
        do j2=1,nlist
            i2 = (atomlist(j2)-1)*3
            dr = xa(i1+1:i1+3) - xb(i2+1:i2+3)
            dr2 = sum( dr**2 )
            q0 = exp( -dr2 * iL2 )
            q = q + q0
            gradient(i2+1 : i2+3) = gradient(i2+1 : i2+3) + (q0 * 2.d0 * iL2) * dr
        end do
    end do
end subroutine overlap_gradient

end module overlap_mod

program test_overlap
    use overlap_mod
    implicit none
    double precision :: result, L2
    integer, parameter :: n = 2, nlist = 2
    integer :: atomlist(nlist)
    double precision :: xa(3*n), xb(3*n), gradient(3*n)

    ! Initialize test data
    L2 = 4.0
    xa = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]
    xb = [1.5, 2.5, 3.5, 4.5, 5.5, 6.5]
    atomlist = [1, 2]

    ! Test overlap function
    result = overlap(xa, xb, L2, n, atomlist, nlist)
    print *, 'Testing overlap function...'
    print *, 'Result:', result

    ! Test overlap_gradient subroutine
    call overlap_gradient(xa, xb, L2, n, atomlist, nlist, result, gradient)
    print *, 'Testing overlap_gradient subroutine...'
    print *, 'Result (q):', result
    print *, 'Gradient:', gradient

end program test_overlap