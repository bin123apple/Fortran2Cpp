module de
contains
  function zu(az, xx) result(q3)
    real :: az, xx, q3
    q3 = 1.0 - lz(az, xx) - lz(xx, az)
  end function zu

  function lz(ho, gh) result(ye)
    real :: ho, gh, ye
    ye = sqrt(ho) - ho * gh
  end function lz
end module de

program test_de
  use de
  implicit none

  real :: az, xx
  real :: result_zu, result_lz

  ! Example input values for testing
  az = 4.0
  xx = 2.0

  ! Test lz function
  result_lz = lz(az, xx)
  print *, "lz(", az, ", ", xx, ") = ", result_lz

  ! Test zu function
  result_zu = zu(az, xx)
  print *, "zu(", az, ", ", xx, ") = ", result_zu
  
  ! You can add more tests here with different values of az and xx
end program test_de