program test_tridiagonal
  implicit none
  integer, parameter :: n = 3, m = 1, lda = 3
  real*8 :: a(lda, 3), b(n)
  integer :: i

  ! Initialize a simple tridiagonal system
  ! Matrix a and vector b as per the example
  a(1, 1) = 0.0
  a(1, 2) = 2.0
  a(1, 3) = -1.0
  a(2, 1) = -1.0
  a(2, 2) = 2.0
  a(2, 3) = -1.0
  a(3, 1) = -1.0
  a(3, 2) = 2.0
  a(3, 3) = 0.0
  b(1) = 1.0
  b(2) = 2.0
  b(3) = 3.0

  call tridiagonal(a, b, n, m, lda)

  print *, "Resulting b:"
  do i = 1, n
     print *, b(i)
  end do
end program test_tridiagonal

subroutine tridiagonal(a, b, n, m, lda)
  implicit none
  integer :: k, n, m, lda
  real*8 :: a(lda,3), b(n), y

  do k = 1, m
     a(k, 3) = a(k, 3) / a(k, 2)
     b(k) = b(k) / a(k, 2)
  end do
  
  do k = m + 1, n - m
     y = 1.d0 / (a(k - m, 3) * a(k, 1) - a(k, 2))
     a(k, 3) = -a(k, 3) * y
     b(k) = (b(k - m) * a(k, 1) - b(k)) * y
  end do
  
  do k = n - m + 1, n
     a(k, 2) = a(k - m, 3) * a(k, 1) - a(k, 2)
     b(k) = (b(k - m) * a(k, 1) - b(k)) / a(k, 2)
  end do
  
  do k = n - m, 1, -1
     b(k) = b(k) - a(k, 3) * b(k + m)
  end do
end subroutine tridiagonal