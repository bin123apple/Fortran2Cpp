program TestBoundaryMassForceMatrix2D
  implicit none
  double precision :: FiS, FiN
  double precision, dimension(2,2) :: TT
  double precision, dimension(2,2) :: RN
  integer :: i, j

  ! Initialize test values
  FiS = 1.0
  FiN = 2.0
  TT(1,1) = 3.0
  TT(2,1) = 4.0
  TT(1,2) = 0.0
  TT(2,2) = 0.0

  ! Call the subroutine to test
  call BoundaryMassForceMatrix2D(FiS, FiN, TT, RN)

  ! Print the results
  print *, "RN matrix:"
  do i = 1, 2
    do j = 1, 2
      print *, "RN(", i, ",", j, ") = ", RN(i,j)
    end do
  end do

contains

  subroutine BoundaryMassForceMatrix2D(FiS, FiN, TT, RN)
    implicit none
    double precision, intent(in) :: FiS, FiN
    double precision, dimension(1:2,1:2), intent(in) :: TT
    double precision, dimension(1:2,1:2), intent(inout) :: RN

    RN(1,1) = FiS * TT(1,1) * TT(1,1) + FiN * TT(2,1) * TT(2,1)
    RN(1,2) = (FiS - FiN) * TT(1,1) * TT(2,1)
    RN(2,1) = RN(1,2)
    RN(2,2) = FiS * TT(2,1) * TT(2,1) + FiN * TT(1,1) * TT(1,1)
  end subroutine BoundaryMassForceMatrix2D

end program TestBoundaryMassForceMatrix2D