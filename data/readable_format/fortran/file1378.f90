! loglikelihood_mod.f90
module precision_mod
  implicit none
  integer, parameter :: dp = selected_real_kind(15, 307)
end module precision_mod

module loglikelihood_mod
  use precision_mod
  implicit none

contains

  subroutine sptransitmodel(nplanet, npars, sol, solrange, nwv, nobs, time, &
       exptime, ntt, tobs, omc, sptmodel, nwvc)
    implicit none
    integer, intent(in) :: nplanet, npars, nwv, nobs, nwvc
    integer, dimension(:), intent(in) :: ntt
    integer, dimension(:,:), intent(in) :: solrange
    real(dp), dimension(:), intent(in) :: sol
    real(dp), dimension(:,:), intent(in) :: time, exptime, tobs, omc
    real(dp), dimension(:,:), intent(inout) :: sptmodel
    ! Dummy implementation, replace with actual calculations
    sptmodel = 1.0_dp
  end subroutine sptransitmodel

  function loglikelihood(nwv, nobs, nplanet, npars, sol, solrange, time, &
       flux, ferr, exptime, ntt, tobs, omc, sptmodel, nwvc) result(ll)
    implicit none
    integer, intent(in) :: nwv, nobs, nplanet, npars, nwvc
    integer, dimension(:), intent(in) :: ntt
    integer, dimension(:,:), intent(in) :: solrange
    real(dp), dimension(:), intent(in) :: sol
    real(dp), dimension(:,:), intent(in) :: time, flux, ferr, exptime, tobs, omc
    real(dp), dimension(:,:), intent(inout) :: sptmodel
    real(dp) :: ll
    real(dp), dimension(:,:), allocatable :: sptmodel1
    real(dp) :: ll1, ll2, ll3, prior

    allocate(sptmodel1(nwv, nobs))
    call sptransitmodel(nplanet, npars, sol, solrange, nwv, nobs, time, exptime, &
         ntt, tobs, omc, sptmodel1, nwvc)

    if (nwvc == 0) then
      sptmodel = sptmodel1
    else
      sptmodel(nwvc,:) = sptmodel1(nwvc,:)
    end if

    ll1 = 0.0_dp
    ll2 = 0.0_dp
    ll3 = sum(((sptmodel - flux)**2) / (ferr**2))

    ll = -0.5_dp * (ll1 + ll2 + ll3)
    prior = 1.0_dp
    ll = ll * prior
  end function loglikelihood

end module loglikelihood_mod

program test_loglikelihood
  use precision_mod
  use loglikelihood_mod
  implicit none
  real(dp) :: result
  integer :: nwv, nobs, nplanet, npars, nwvc
  integer, allocatable :: ntt(:), solrange(:,:)
  real(dp), allocatable :: sol(:), time(:,:), flux(:,:), ferr(:,:), exptime(:,:), tobs(:,:), omc(:,:), sptmodel(:,:)

  ! Example initialization for testing purposes
  nwv = 1
  nobs = 1
  nplanet = 1
  npars = 1
  nwvc = 0
  allocate(sol(1), solrange(1,1), time(1,1), flux(1,1), ferr(1,1), exptime(1,1), tobs(1,1), omc(1,1), sptmodel(1,1), ntt(1))
  sol(1) = 0.5_dp
  solrange(1,1) = 1
  time(1,1) = 0.5_dp
  flux(1,1) = 1.0_dp
  ferr(1,1) = 0.1_dp
  exptime(1,1) = 0.5_dp
  tobs(1,1) = 0.5_dp
  omc(1,1) = 0.0_dp
  sptmodel(1,1) = 1.0_dp
  ntt(1) = 0

  result = loglikelihood(nwv, nobs, nplanet, npars, sol, solrange, time, flux, ferr, exptime, ntt, tobs, omc, sptmodel, nwvc)
  print *, "Loglikelihood result:", result
end program test_loglikelihood