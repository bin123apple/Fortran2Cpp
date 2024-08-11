program openacc_clause_validity_test

  implicit none

  integer :: i, N
  real(8) :: a(256)

  N = 256

  ! Initialize the array
  a = 0.0

  ! Execute the original code
  call original_code(a, N)

  ! Verify the results
  do i = 1, N
    if (a(i) /= 3.14) then
      print *, 'Test failed at index ', i
      stop
    end if
  end do

  print *, 'All tests passed.'

contains

  subroutine original_code(a, N)
    implicit none
    integer, intent(in) :: N
    real(8), intent(inout) :: a(N)
    integer :: i

    !$acc parallel loop
    do i = 1, N
      a(i) = 3.14
    end do
    !$acc end parallel loop

  end subroutine original_code

end program openacc_clause_validity_test