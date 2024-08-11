module m_tenstr_parkind_lw
  implicit none
  integer, parameter :: kind_im = 4
  integer, parameter :: kind_rb = 8
end module m_tenstr_parkind_lw

module m_tenstr_rrlw_kg03
  use m_tenstr_parkind_lw, only: kind_im, kind_rb
  implicit none
  integer(kind=kind_im), parameter :: no3 = 16
  real(kind=kind_rb) :: fracrefao(no3,9)
end module m_tenstr_rrlw_kg03

program test_m_tenstr_rrlw_kg03
  use m_tenstr_rrlw_kg03
  implicit none
  fracrefao(1,1) = 123.45_kind_rb
  print *, "Fortran fracrefao(1,1) =", fracrefao(1,1)
end program test_m_tenstr_rrlw_kg03