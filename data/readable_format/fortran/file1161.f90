program test_correct_flux
  implicit none
  integer, parameter :: n = 3
  real, dimension(n) :: velocity, area, flux_in, flux_out
  real :: correction
  integer :: i

  ! Test setup
  velocity = (/ 0.0, 2.0, -1.0 /)
  area = (/ 1.0, 1.0, 1.0 /)
  flux_in = (/ 100.0, 200.0, 300.0 /)
  correction = 1.5

  ! Call the subroutine
  call correct_flux(n, velocity, area, flux_in, flux_out, correction)

  ! Output results for manual verification
  do i = 1, n
     print *, "Element", i, "Flux Out:", flux_out(i)
  end do

  ! Define the subroutine
  contains

    subroutine correct_flux(n, velocity, area, flux_in, flux_out, correction)
      integer, intent(in) :: n
      real, dimension(n), intent(in) :: velocity, area, flux_in
      real, dimension(n), intent(out) :: flux_out
      real, intent(in) :: correction
      integer :: i

      do i = 1, n
         if (velocity(i) > 0.0) then
            flux_out(i) = flux_in(i) * area(i) * correction
         else
            flux_out(i) = flux_in(i)
         end if
      end do
    end subroutine correct_flux

end program test_correct_flux