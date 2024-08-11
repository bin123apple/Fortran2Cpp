program testEval
  implicit none
  double precision, allocatable :: foo3(:), foo4(:), x(:)
  double precision :: foo1, foo2
  integer :: n, nnd, i

  ! Initialize test parameters
  foo1 = 1.0d0
  foo2 = 2.0d0
  n = 3
  nnd = 5
  allocate(foo3(n), foo4(n), x(nnd))

  ! Populate arrays with test data
  foo4 = (/1.0d0, 2.0d0, 3.0d0/)
  x = (/0.0d0, 1.0d0, 2.0d0, 3.0d0, 4.0d0/)

  ! Call subroutine
  call eval(foo1, foo2, foo3, foo4, x, n, nnd)

  ! Output results (for verification)
  print *, 'foo3:'
  do i = 1, n
    print *, foo3(i)
  end do

  ! Deallocate arrays
  deallocate(foo3, foo4, x)

contains

  subroutine eval(foo1, foo2, foo3, foo4, x, n, nnd)
    implicit none
    double precision :: foo1, foo2
    double precision, dimension(n) :: foo3, foo4
    double precision, dimension(nnd) :: x
    integer :: i, j, k, jmini, n, nnd
    double precision :: temp

    foo3(1) = foo2 * foo4(1)
    do i = 2, n
      foo3(i) = foo2 * foo4(i)
      do j = 1, i-1
        temp = 0.0d0
        jmini = j - i
        do k = i, nnd, n
          temp = temp + (x(k) - x(k + jmini))**2
        end do
        temp = sqrt(temp + foo1)
        foo3(i) = foo3(i) + temp * foo4(j)
        foo3(j) = foo3(j) + temp * foo4(i)
      end do
    end do
  end subroutine eval

end program testEval