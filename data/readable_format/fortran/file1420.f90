! essai.f90
program ESSAI
  implicit none

  INTEGER, parameter :: NbDim = 3
  INTEGER, parameter :: NbPoints = 5

  DOUBLE PRECISION, dimension(NbDim, NbPoints) :: Points
  DOUBLE PRECISION, dimension(NbDim) :: Deplacement

  ! Initialization
  data Deplacement / 0.5, -2.5, 3.0 /
  Points = reshape((/ 0., 5., 10., 1., 6., 11., 2., 7., 12., 3., 8., 13., 4., 9., 14. /), shape(Points))

  ! Display initial values
  print*, '-- tableau deplacement --', Deplacement
  print*, '-- tableau de points  --', Points

  ! Call subroutine to modify points
  call changer_coordonnees(Deplacement, NbPoints, Points)

  ! Display modified points
  print*, '-- tableau de points (apres) --', Points

  ! Run unit tests
  call test_changer_coordonnees

contains

  subroutine changer_coordonnees(Deplacement, NbPoints, Points)
    INTEGER, parameter :: NbDim = 3
    INTEGER, intent(in) :: NbPoints
    DOUBLE PRECISION, intent(inout), dimension(NbDim, NbPoints) :: Points
    DOUBLE PRECISION, intent(in), dimension(NbDim) :: Deplacement

    INTEGER :: c, l
    do l=1, NbPoints
      do c=1, NbDim
        Points(c, l) = Points(c, l) + Deplacement(c)
      end do
    end do
  end subroutine changer_coordonnees

  subroutine test_changer_coordonnees
    implicit none

    DOUBLE PRECISION, dimension(NbDim, NbPoints) :: TestPoints
    DOUBLE PRECISION, dimension(NbDim) :: TestDeplacement
    DOUBLE PRECISION, dimension(NbDim, NbPoints) :: ExpectedPoints
    INTEGER :: c, l
    logical :: test_passed

    ! Initialize test data
    TestDeplacement = (/ 0.5, -2.5, 3.0 /)
    TestPoints = reshape((/ 0., 5., 10., 1., 6., 11., 2., 7., 12., 3., 8., 13., 4., 9., 14. /), shape(TestPoints))
    ExpectedPoints = reshape((/ 0.5, 2.5, 13., 1.5, 3.5, 14., 2.5, 4.5, 15., 3.5, 5.5, 16., 4.5, 6.5, 17. /), shape(ExpectedPoints))

    ! Apply displacement
    call changer_coordonnees(TestDeplacement, NbPoints, TestPoints)

    ! Validate results
    test_passed = .TRUE.
    do l = 1, NbPoints
      do c = 1, NbDim
        if (TestPoints(c, l) /= ExpectedPoints(c, l)) then
          test_passed = .FALSE.
          exit
        endif
      end do
      if (.not. test_passed) exit
    end do

    if (test_passed) then
      print*, "Fortran Unit Test PASSED."
    else
      print*, "Fortran Unit Test FAILED."
    endif
  end subroutine test_changer_coordonnees

end program ESSAI