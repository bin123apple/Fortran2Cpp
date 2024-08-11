program e_50_3_combined
  implicit none

contains

  subroutine init(v1, v2, N)
    integer :: N
    real :: v1(N), v2(N)
    integer :: i
    do i = 1, N
      v1(i) = i + 2.0
      v2(i) = i - 3.0
    end do
  end subroutine init

  subroutine check(p, N)
    integer :: N
    real :: p(N)
    real, parameter :: EPS = 0.00001
    integer :: i
    real :: diff
    do i = 1, N
      diff = p(i) - (i + 2.0) * (i - 3.0)
      if (diff > EPS .or. -diff > EPS) then
        print *, "Check failed at index ", i, " with difference ", diff
        stop 1
      endif
    end do
  end subroutine check

  subroutine vec_mult(N)
    integer :: N
    real :: p(N), v1(N), v2(N)
    integer :: i
    call init(v1, v2, N)
    !$omp target map(to: v1,v2) map(from: p)
      !$omp parallel do
      do i = 1, N
        p(i) = v1(i) * v2(i)
      end do
    !$omp end target
    call check(p, N)
  end subroutine vec_mult

  subroutine test_vec_mult
    integer :: n

    ! Test case 1: Small size
    n = 10
    call vec_mult(n)
    print *, "Test case 1 passed."

    ! Test case 2: Medium size
    n = 100
    call vec_mult(n)
    print *, "Test case 2 passed."

    ! Test case 3: Larger size
    n = 1000
    call vec_mult(n)
    print *, "Test case 3 passed."

    ! Add more test cases as needed
  end subroutine test_vec_mult

end program e_50_3_combined