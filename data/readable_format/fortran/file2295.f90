! tridiagonal.f90
program test_tridiagonal
    implicit none
    integer, parameter :: n = 5, m = 1, lda = 3
    double precision :: a(lda, n), b(n)
    integer :: i

    ! Initialize matrix 'a' and vector 'b'
    do i = 1, n
        a(1, i) = 1.0d0
        a(2, i) = 2.0d0
        a(3, i) = 3.0d0
        b(i) = 4.0d0
    end do

    call tridiagonal(a, b, n, m, lda)

    ! Print the result
    print *, "Resulting b:"
    do i = 1, n
        print *, b(i)
    end do
end program test_tridiagonal

subroutine tridiagonal(a, b, n, m, lda)
    implicit none
    integer :: k, n, m, lda
    double precision :: a(lda, n), b(n), y

    do k = 1, m
        a(3, k) = a(3, k) / a(2, k)
        b(k) = b(k) / a(2, k)
    end do

    do k = m + 1, n - m
        y = 1.0d0 / (a(1, k) * a(3, k - m) - a(2, k))
        a(3, k) = -a(3, k) * y
        b(k) = (b(k - m) * a(1, k) - b(k)) * y
    end do

    do k = n - m + 1, n
        a(2, k) = a(1, k) * a(3, k - m) - a(2, k)
        b(k) = (b(k - m) * a(1, k) - b(k)) / a(2, k)
    end do

    do k = n - m, 1, -1
        b(k) = b(k) - a(3, k) * b(k + m)
    end do
end subroutine tridiagonal