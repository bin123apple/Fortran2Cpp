! CombinedFile.f90
Program TestABSHM
  Implicit None
  
  ! Test Case
  Print *, "Test 1 (T=25, DP=unused, Q=1000): Expected output, Got ", ABSHM(25.0, 0.0, 1000.0)

Contains

  ! Function Definition
  Function ABSHM(T, DP, Q)
    Implicit None
    Real :: ABSHM
    Real, Intent(In) :: T, DP, Q
    
    ABSHM = Q / (461.5E-05 * (T + 273.16))
  End Function ABSHM

End Program TestABSHM