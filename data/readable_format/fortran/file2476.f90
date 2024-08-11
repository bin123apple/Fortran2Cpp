module e_54_5_mod
contains
  subroutine init (v1, v2, N)
    integer :: i, N
    real, dimension(:), allocatable :: v1, v2
    do i = 1, N
      v1(i) = i + 2.0
      v2(i) = i - 3.0
    end do
  end subroutine

  subroutine check (p, N)
    integer :: i, N
    real, parameter :: EPS = 0.00001
    real, dimension(:), allocatable :: p
    real :: diff
    do i = 1, N
      diff = p(i) - (i + 2.0) * (i - 3.0)
      if (diff > EPS .or. -diff > EPS) then
        print *, "Check failed at index:", i
        stop
      endif
    end do
  end subroutine

  subroutine vec_mult (p, v1, v2, N)
    real, dimension(:), allocatable :: p, v1, v2
    integer :: i, N
    do i = 1, N
        p(i) = v1(i) * v2(i)
    end do
  end subroutine
end module

program e_54_5_test
  use e_54_5_mod, only : init, check, vec_mult
  integer :: n
  real, allocatable :: p(:), v1(:), v2(:)
  
  n = 1000
  allocate (p(n), v1(n), v2(n))
  
  call init (v1, v2, n)
  call vec_mult (p, v1, v2, n)
  call check (p, n)
  
  print *, "Fortran test passed."
  
  deallocate (p, v1, v2)
end program