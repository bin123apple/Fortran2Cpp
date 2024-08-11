module conref_C
  implicit none
  ! Using kind=8 for double precision, a widely supported convention
  real(kind=8), dimension(2,10) :: fpcref

  ! Initialize the fpcref array
  ! Note: Direct initialization within a module without BLOCK DATA
  !       or DATA statements might need to be replaced with assignments
  !       in a CONTAINS section or initialization in a program or subroutine
contains
  subroutine init_fpcref()
    fpcref(1, 1) = 1.602176462d0
    fpcref(2, 1) = 1.60217733d0
    fpcref(1, 2) = 14.399643d0
    fpcref(2, 2) = 14.399d0
    fpcref(1, 3) = 0.5291772083d0
    fpcref(2, 3) = 0.529167d0
    fpcref(1, 4) = 27.2113834d0
    fpcref(2, 4) = 27.21d0
    fpcref(1, 5) = 1.9872065d0
    fpcref(2, 5) = 1.98726d0
    fpcref(1, 6) = 6.6260755d-27
    fpcref(2, 6) = 6.626d-27
    fpcref(1, 7) = 1.3806503d-16
    fpcref(2, 7) = 1.3807d-16
    fpcref(1, 8) = 2.99792458d+10
    fpcref(2, 8) = 2.99776d+10
    fpcref(1, 9) = 23.060529d0
    fpcref(2, 9) = 23.061d0
    fpcref(1, 10) = 6.0221367d23
    fpcref(2, 10) = 6.02205d23
  end subroutine init_fpcref
end module conref_C

program test_conref_C
  use conref_C
  implicit none

  call init_fpcref()

  ! After initialization, you can add your tests here
  ! For example, to print the values:
  print *, 'fpcref(1,1) = ', fpcref(1,1)
  print *, 'fpcref(2,10) = ', fpcref(2,10)

end program test_conref_C