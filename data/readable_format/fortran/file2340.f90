module bitmasks
  use, intrinsic :: iso_fortran_env, only: int32
  implicit none
  integer(int32), parameter :: N_int = 10
  integer(int32), dimension(N_int, 2) :: act_bitmask, reunion_of_core_inact_bitmask, virt_bitmask
contains
  subroutine initialize_bitmasks()
    integer :: i
    do i = 1, N_int
      act_bitmask(i, 1) = 1
      act_bitmask(i, 2) = 1
      reunion_of_core_inact_bitmask(i, 1) = 2
      reunion_of_core_inact_bitmask(i, 2) = 2
      virt_bitmask(i, 1) = 3
      virt_bitmask(i, 2) = 3
    end do
  end subroutine
end module bitmasks

module determinant_functions
  use, intrinsic :: iso_fortran_env, only: int32
  implicit none
contains
  subroutine give_active_part_determinant(det_in, det_out)
    use bitmasks
    integer(int32), intent(in) :: det_in(N_int, 2)
    integer(int32), intent(out) :: det_out(N_int, 2)
    integer :: i
    do i = 1, N_int
      det_out(i, 1) = iand(det_in(i, 1), act_bitmask(i, 1))
      det_out(i, 2) = iand(det_in(i, 2), act_bitmask(i, 2))
    end do
  end subroutine
end module determinant_functions

program test_fortran
  use bitmasks
  use determinant_functions
  implicit none
  integer(int32), dimension(N_int, 2) :: det_in, det_out, expected_out
  integer :: i, errors

  call initialize_bitmasks()

  ! Initialize the input arrays with test values
  do i = 1, N_int
    det_in(i, 1) = i
    det_in(i, 2) = i + 1
  end do

  ! Expected outputs
  do i = 1, N_int
    expected_out(i, 1) = iand(det_in(i, 1), act_bitmask(i, 1))
    expected_out(i, 2) = iand(det_in(i, 2), act_bitmask(i, 2))
  end do

  ! Call the subroutine and check results
  call give_active_part_determinant(det_in, det_out)
  errors = 0
  do i = 1, N_int
    if (det_out(i, 1) /= expected_out(i, 1) .or. det_out(i, 2) /= expected_out(i, 2)) then
      errors = errors + 1
    end if
  end do

  if (errors == 0) then
    print *, 'give_active_part_determinant passed.'
  else
    print *, 'give_active_part_determinant failed with ', errors, ' errors.'
  end if
end program test_fortran