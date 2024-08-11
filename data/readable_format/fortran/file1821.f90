module adios_helpers_mod
  implicit none
contains
  subroutine define_adios_scalar(scalar)
    real, intent(in) :: scalar
    print *, "Defining ADIOS scalar with value: ", scalar
  end subroutine define_adios_scalar

  subroutine define_adios_global_real_1d_array(array, size)
    real, dimension(:), intent(in) :: array
    integer, intent(in) :: size
    print *, "Defining ADIOS global real 1D array of size ", size
    print *, array
  end subroutine define_adios_global_real_1d_array

  subroutine check_adios_err()
    print *, "Checking for ADIOS errors..."
  end subroutine check_adios_err
end module adios_helpers_mod

program test_adios_helpers
  use adios_helpers_mod
  implicit none

  real :: scalar_value
  real, dimension(5) :: array
  integer :: i

  ! Test define_adios_scalar
  scalar_value = 3.14
  call define_adios_scalar(scalar_value)

  ! Test define_adios_global_real_1d_array
  do i = 1, 5
     array(i) = i * 2.0
  end do
  call define_adios_global_real_1d_array(array, 5)

  ! Test check_adios_err
  call check_adios_err()

end program test_adios_helpers