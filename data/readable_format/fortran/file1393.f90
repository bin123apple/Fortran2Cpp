program test_init_pars
  implicit none
  real*8 :: al
  real*8 :: beta

  call init_pars(al, beta)

  if (al == 16d0 .and. beta == 128d0) then
    print *, "Test passed."
  else
    print *, "Test failed."
  end if
contains

  subroutine init_pars(al, beta)
    implicit none
    real*8 :: al
    real*8 :: beta
    al = 16d0
    beta = 128d0
  end subroutine init_pars

end program test_init_pars