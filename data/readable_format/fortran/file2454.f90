program test_nombre_dor
  implicit none
  real, parameter :: epsilon = 1.e-5
  real            :: expected_nombre_or
  real            :: computed_nombre_or
  real            :: computed_limite_suite

  call nombre_dor(computed_limite_suite, computed_nombre_or)

  expected_nombre_or = (1. + sqrt(5.))/2.

  if (abs(computed_nombre_or - expected_nombre_or) < epsilon) then
    print*, "Test Passed: Nombre d'or is correct."
  else
    print*, "Test Failed: Nombre d'or is incorrect."
  end if

  if (abs(computed_limite_suite - expected_nombre_or) < epsilon) then
    print*, "Test Passed: Limite de la suite (vn) is correct."
  else
    print*, "Test Failed: Limite de la suite (vn) is incorrect."
  end if
end program test_nombre_dor

subroutine nombre_dor(limite_suite, nombre_or)
  implicit none
  real, parameter   :: epsilon = 1.e-5
  real              :: u_prec, u_cour
  real              :: v_prec, v_cour
  real              :: somme
  real              :: nombre_or
  real, intent(out) :: limite_suite

  nombre_or = (1. + sqrt(5.))/2.

  u_prec = 1.; u_cour = 1.
  do
    v_prec = u_cour/u_prec
    somme  = u_cour + u_prec
    u_prec = u_cour
    u_cour = somme
    v_cour = u_cour/u_prec
    if ( abs( (v_cour-v_prec)/v_prec ) < epsilon ) exit
  end do

  limite_suite = v_cour
end subroutine nombre_dor