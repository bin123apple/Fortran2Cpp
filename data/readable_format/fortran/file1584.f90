program elastic_energy_program
  implicit none
  integer, parameter :: nelemg = 1, nume = 1
  real, dimension(nelemg) :: sign1, sign2, sign3, sign4
  real, dimension(nume) :: Y_modulus, possion_ratio, tau_y
  integer :: nftm1
  integer :: ele
  real :: qe

  ! Initialize values
  sign1 = 0.1
  sign2 = 0.2
  sign3 = 0.3  ! Unused in the calculation but initialized for completeness
  sign4 = 0.4
  Y_modulus = 210.0
  possion_ratio = 0.3
  tau_y = 100.0  ! Unused in the calculation but initialized for completeness
  nftm1 = 0

  ele = 1
  call elastic_energy(ele, qe)

  print *, "Computed elastic energy: ", qe

contains

  subroutine elastic_energy(ele, qe)
    integer, intent(in) :: ele
    real, intent(out) :: qe
    integer :: ink
    real :: E, v, epx, epy, epxy

    qe = 0.0
    ink = ele + nftm1
    E = Y_modulus(ink)
    v = possion_ratio(ink)

    epx = (1+v)/E*((1-v)*sign1(ele)-v*sign2(ele))
    epy = (1+v)/E*(-v*sign1(ele)+(1-v)*sign2(ele))
    epxy = (1+v)/E*2*sign4(ele)

    qe = (sign1(ele)*epx + sign2(ele)*epy + sign4(ele)*epxy) / 2.0
  end subroutine elastic_energy

end program elastic_energy_program