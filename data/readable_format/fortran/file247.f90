program test
  implicit none
  integer :: a(100), i, j, k, s

  ! Test values
  i = 2
  j = 1
  k = 10
  s = 1

  ! Initialize array
  a = 0

  ! Test foo
  call foo(i, j, k, s, a)
  print *, 'Test foo:', a(1:10)

  ! Reset array
  a = 0

  ! Test bar
  call bar(i, j, k, s, a)
  print *, 'Test bar:', a(1:10)

contains

  subroutine foo(i, j, k, s, a)
    integer :: i, j, k, s, a(100)
    integer :: l
    !$omp parallel do schedule(dynamic, s * 2)
    do l = j, k
      a(l) = i
    end do
    !$omp parallel do schedule(dynamic, s * 2)
    do l = j, k, 3
      a(l) = i + 1
    end do
  end subroutine foo

  subroutine bar(i, j, k, s, a)
    integer :: i, j, k, s, a(100)
    integer :: l
    !$omp parallel do schedule(guided, s * 2)
    do l = j, k
      a(l) = i
    end do
    !$omp parallel do schedule(guided, s * 2)
    do l = j, k, 3
      a(l) = i + 1
    end do
  end subroutine bar

end program test