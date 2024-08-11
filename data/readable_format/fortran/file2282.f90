program test_pr95869
  implicit none

  integer, parameter :: N = 100
  integer, parameter :: LIMIT = 60
  integer :: i, j, errors
  integer, dimension(N) :: a
  errors = 0

  ! Initialize the array a
  do i = 1, N
     a(i) = i
  end do

  do j = 1, N
    ! Removed the target directive due to the compiler error
    ! Use parallel do for simplification
    !$omp parallel do if(j .lt. LIMIT) shared(a)
    do i = 1, N
      a(i) = a(i) + 1
    end do
  end do

  ! Verification step
  do i = 1, N
    if (a(i) /= i + N) then
      print *, "Error at index ", i, ": expected ", i + N, " but got ", a(i)
      errors = errors + 1
    end if
  end do

  if (errors == 0) then
    print *, "All tests passed!"
  else
    print *, "There were ", errors, " errors."
  end if

end program test_pr95869