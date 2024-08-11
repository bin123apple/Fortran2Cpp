program test_polytrope_eos
  implicit none

  ! Type definition directly inside the program
  type :: poly_eos
     double precision :: K, gamma
     double precision :: rho, e
     double precision :: drho_dp, de_dp
     double precision :: p
  end type poly_eos

  type(poly_eos) :: eos_data
  double precision :: tolerance
  double precision :: K, gamma, pres, dens
  double precision :: expected_rho, expected_p

  ! Initialize the EOS
  K = 1.0d0
  gamma = 1.4d0
  call eos_init(K, gamma)

  ! Tolerance for floating-point comparisons
  tolerance = 1.0d-12

  ! Test eos_p
  pres = 10.0d0
  expected_rho = (pres / K)**(1.0d0 / gamma)
  call eos_p(pres)
  if (abs(eos_data%rho - expected_rho) < tolerance) then
    print *, "eos_p test passed"
  else
    print *, "eos_p test failed"
  end if

  ! Test eos_rho
  dens = 0.1d0
  expected_p = K * (dens**gamma)
  call eos_rho(dens)
  if (abs(eos_data%p - expected_p) < tolerance) then
    print *, "eos_rho test passed"
  else
    print *, "eos_rho test failed"
  end if

contains

  subroutine eos_init(K, gamma)
    double precision, intent(in) :: K, gamma
    eos_data%K = K
    eos_data%gamma = gamma
  end subroutine eos_init
  
  subroutine eos_p(pres)
    double precision, intent(in) :: pres
    eos_data%p = pres
    eos_data%rho = (eos_data%p/eos_data%K)**(1.0d0/eos_data%gamma)
    call eos_compute()
  end subroutine eos_p

  subroutine eos_rho(dens)
    double precision, intent(in) :: dens
    eos_data%rho = dens
    eos_data%p = eos_data%K * (eos_data%rho**eos_data%gamma)
    call eos_compute()
  end subroutine eos_rho

  subroutine eos_compute()
    eos_data%e = (eos_data%p/eos_data%rho)/(eos_data%gamma - 1.0d0)
    eos_data%drho_dp = (1.0d0/(eos_data%K*eos_data%gamma))* &
         eos_data%rho**(1.0d0-eos_data%gamma)
    eos_data%de_dp = (-eos_data%p/(eos_data%gamma - 1.0d0)/ &
         (eos_data%rho**2))*eos_data%drho_dp + &
         (1.0d0/eos_data%rho/(eos_data%gamma - 1.0d0))
  end subroutine eos_compute

end program test_polytrope_eos