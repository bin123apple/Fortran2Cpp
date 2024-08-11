program test_uboun
  implicit none
  double precision :: boun
  double precision, dimension(3) :: coords
  double precision, dimension(2) :: time
  integer, dimension(3) :: mi
  integer :: node, idof, kstep, kinc, ntmat_

  ! Assuming some values for variables not directly relevant to the calculation
  time = (/0.0d0, 1.0d0/)
  node = 1
  idof = 1
  kstep = 1
  kinc = 1
  ntmat_ = 1
  mi = (/1, 1, 1/)

  ! Test case 1
  coords = (/0.0d0, 0.0d0, 0.0d0/) ! Should result in boun=300.0
  call uboun(boun,coords)
  print *, 'Coords: ', coords, ' Boun:', boun

  ! Test case 2
  coords = (/0.0d0, 1.0d0, 0.0d0/) ! Should result in boun=225.0
  call uboun(boun,coords)
  print *, 'Coords: ', coords, ' Boun:', boun

  ! Test case 3
  coords = (/0.0d0, 2.0d0, 0.0d0/) ! Should result in boun=0.0
  call uboun(boun,coords)
  print *, 'Coords: ', coords, ' Boun:', boun

contains

  subroutine uboun(boun, coords)
    implicit none
    double precision, intent(out) :: boun
    double precision, intent(in), dimension(3) :: coords

    boun = 300.d0 / 8.d0 * (4.d0 - coords(2) * coords(2))

  end subroutine uboun

end program test_uboun