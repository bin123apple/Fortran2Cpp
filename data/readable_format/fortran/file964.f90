program test_schmib
    implicit none
    double precision, allocatable :: u(:,:)
    integer :: n, ndim, i, j

    ! Define matrix dimensions
    n = 3
    ndim = 3
    allocate(u(ndim,ndim))

    ! Initialize the matrix u.
    u = reshape((/ 1.d0, 2.d0, 3.d0, &
                  2.d0, 5.d0, 6.d0, &
                  3.d0, 6.d0, 14.d0 /), &
                 shape(u), order=[2,1])

    ! Call the subroutine.
    call schmib(u, n, ndim)

    ! Print the result.
    print *, 'Resulting matrix U after schmib processing:'
    do i = 1, ndim
        print '(3F10.5)', u(i,:)
    end do
end program test_schmib

subroutine schmib(u, n, ndim)
    implicit none
    integer, intent(in) :: n, ndim
    double precision, intent(inout) :: u(ndim,ndim)
    integer :: n1, ii, k, k1, npass, j
    double precision :: zero, small, one, dot, scale

    zero = 0.0d0
    small = 0.01d0
    one = 1.0d0
    n1 = n + 1
    ii = 0

    do k = 1, n
        k1 = k - 1
        dot = sum(u(:,n1-k)**2)
        if (abs(dot) < 1.d-20) then
            ii = ii + 1
            if (ii <= ndim) u(ii,n1-k) = one
            cycle
        endif
        scale = one/sqrt(dot)
        u(:,n1-k) = scale*u(:,n1-k)
        if (k1 == 0) cycle
        npass = 0
        do while (npass < 3)
            npass = npass + 1
            do j = 1, k1
                dot = sum(u(:,n1-j)*u(:,n1-k))
                u(:,n1-k) = u(:,n1-k) - dot*u(:,n1-j)
            end do
            dot = sum(u(:,n1-k)**2)
            if (abs(dot) < 1.d-20) exit
            if (dot < small .and. npass > 1) exit
            scale = one/sqrt(dot)
            u(:,n1-k) = scale*u(:,n1-k)
            if (dot >= small) exit
        end do
        ii = ii + 1
        if (ii <= ndim) u(ii,n1-k) = one
    end do
end subroutine schmib