module coop_HSTlike_mod
  implicit none

  ! Assuming COOP_REAL to be a kind of real number, for simplicity we use the default
  integer, parameter :: COOP_REAL = selected_real_kind(p=6)

  type coop_HST_object
     real(kind=COOP_REAL) :: H0 = 74.03_COOP_REAL
     real(kind=COOP_REAL) :: H0_err = 1.42_COOP_REAL
   contains
     procedure :: LogLike => coop_HST_object_LogLike
  end type coop_HST_object

contains

  function coop_HST_object_LogLike(this, h_value) result(logLike)
    class(coop_HST_object), intent(in) :: this
    real(kind=COOP_REAL), intent(in) :: h_value
    real(kind=COOP_REAL) :: logLike

    logLike = ((h_value*100.0_COOP_REAL - this%H0) / this%H0_err)**2 / 2.0_COOP_REAL
  end function coop_HST_object_LogLike

end module coop_HSTlike_mod

program test_coop_HSTlike
  use coop_HSTlike_mod
  implicit none

  type(coop_HST_object) :: hst
  real(kind=COOP_REAL) :: expected_loglike, computed_loglike, h_value

  ! Example h_value
  h_value = 0.74_COOP_REAL

  ! Expected log likelihood value for given h_value
  expected_loglike = ((h_value*100.0_COOP_REAL - hst%H0) / hst%H0_err)**2 / 2.0_COOP_REAL

  ! Compute the log likelihood
  computed_loglike = hst%LogLike(h_value)

  ! Check if the computed value matches the expected value
  if (abs(computed_loglike - expected_loglike) < 1.0e-6_COOP_REAL) then
    print *, "Test passed."
  else
    print *, "Test failed. Expected:", expected_loglike, "Got:", computed_loglike
  end if
end program test_coop_HSTlike