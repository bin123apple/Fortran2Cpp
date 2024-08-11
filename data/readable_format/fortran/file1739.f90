PROGRAM Main
  IMPLICIT NONE

  INTEGER, PARAMETER :: dp = KIND(1.0D0)
  REAL(KIND=dp), PARAMETER :: bohr_r=0.05291772108_dp
  REAL(KIND=dp), PARAMETER :: hbarc = 197.326968_dp
  REAL(KIND=dp), PARAMETER :: pi = 3.141592741012573_dp
  REAL(KIND=dp), PARAMETER :: pi_2 = 1.570796370506287_dp
  REAL(KIND=dp), PARAMETER :: pi_4 = 0.7853981852531433_dp

  TYPE SpQuantumNumbers
     INTEGER :: TotalOrbits
     INTEGER, DIMENSION(:), ALLOCATABLE :: n, s, ms, parity
     REAL(KIND=dp), DIMENSION(:), ALLOCATABLE :: masses, energy
  END TYPE SpQuantumNumbers

  TYPE, EXTENDS(SpQuantumNumbers) :: TwoDim
     INTEGER, DIMENSION(:), ALLOCATABLE :: ml
  END TYPE TwoDim

  TYPE, EXTENDS(TwoDim) :: ThreeDim
     INTEGER, DIMENSION(:), ALLOCATABLE :: l, j, mj
  END TYPE ThreeDim

  TYPE, EXTENDS(ThreeDim) :: nucleons
     INTEGER, DIMENSION(:), ALLOCATABLE :: t, tz
  END TYPE nucleons

  TYPE, EXTENDS(nucleons) :: hyperons
     INTEGER, DIMENSION(:), ALLOCATABLE :: strange
  END TYPE hyperons

  ! Example usage
  TYPE(hyperons) :: myHyperons
  INTEGER :: i
  
  ! Initialize and use the variables as needed
  ALLOCATE(myHyperons%strange(2))
  myHyperons%strange = (/ -1, 0 /)
  PRINT *, "Strange quantum numbers: "
  DO i = 1, SIZE(myHyperons%strange)
     PRINT *, myHyperons%strange(i)
  END DO

END PROGRAM Main