program test_get_alpha_pv
  use, intrinsic :: iso_fortran_env, only: real64
  implicit none
  complex(real64) :: result
  integer, parameter :: dp = real64
  integer, parameter :: nbnd = 5, nks = 10
  real(dp) :: et(nbnd, nks)
  integer :: ibnd, iks

  ! Initialize the et array with some values for demonstration purposes
  do iks = 1, nks
     do ibnd = 1, nbnd
        et(ibnd, iks) = real(ibnd + iks, dp)
     end do
  end do

  result = get_alpha_pv(nbnd, nks, et)
  print *, 'get_alpha_pv result:', result

contains

  function get_alpha_pv(nbnd, nks, et) result(alpha_pv_complex)
    integer, intent(in) :: nbnd, nks
    real(dp), intent(in) :: et(nbnd, nks)
    complex(dp) :: alpha_pv_complex
    real(dp) :: emin, emax, alpha_pv
    integer :: ibnd, iks

    emin = et(1, 1)
    emax = et(1, 1)
    
    do iks = 1, nks
       do ibnd = 1, nbnd
          emin = min(emin, et(ibnd, iks))
          emax = max(emax, et(ibnd, iks))
       end do
    end do

    alpha_pv = 2.0_dp * (emax - emin)
    alpha_pv = max(alpha_pv, 1.0e-2_dp)
    alpha_pv_complex = cmplx(alpha_pv, 0.0_dp, kind=dp)
  end function get_alpha_pv

end program test_get_alpha_pv