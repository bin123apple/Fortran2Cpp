MODULE SLCTSXMod
  IMPLICIT NONE
CONTAINS
  LOGICAL FUNCTION SLCTSX(AR, AI, BETA)
    REAL, INTENT(IN) :: AR, AI, BETA
    INTEGER :: M, N, MPLUSN, I
    LOGICAL :: FS
    COMMON /MN/ M, N, MPLUSN, I, FS

    IF (FS) THEN
      I = I + 1
      IF (I <= M) THEN
        SLCTSX = .FALSE.
      ELSE
        SLCTSX = .TRUE.
      END IF
      IF (I == MPLUSN) THEN
        FS = .FALSE.
        I = 0
      END IF
    ELSE
      I = I + 1
      IF (I <= N) THEN
        SLCTSX = .TRUE.
      ELSE
        SLCTSX = .FALSE.
      END IF
      IF (I == MPLUSN) THEN
        FS = .TRUE.
        I = 0
      END IF
    END IF
  END FUNCTION SLCTSX
END MODULE SLCTSXMod

PROGRAM TestSLCTSX
  USE SLCTSXMod
  IMPLICIT NONE
  REAL :: AR, AI, BETA
  LOGICAL :: RESULT
  INTEGER :: M, N, MPLUSN, I
  LOGICAL :: FS
  COMMON /MN/ M, N, MPLUSN, I, FS

  ! Initialize the COMMON block variables
  M = 2
  N = 3
  MPLUSN = 5
  I = 0
  FS = .TRUE.
  AR = 1.0
  AI = 2.0
  BETA = 3.0

  ! Test 1
  PRINT *, 'Test 1: FS initially TRUE'
  RESULT = SLCTSX(AR, AI, BETA)
  PRINT *, 'Expected: FALSE, Got: ', RESULT

  ! Test 2
  I = 3
  PRINT *, 'Test 2: FS initially TRUE, I > M'
  RESULT = SLCTSX(AR, AI, BETA)
  PRINT *, 'Expected: TRUE, Got: ', RESULT

  ! Test 3
  I = 0
  FS = .FALSE.
  PRINT *, 'Test 3: FS initially FALSE'
  RESULT = SLCTSX(AR, AI, BETA)
  PRINT *, 'Expected: TRUE, Got: ', RESULT
END PROGRAM TestSLCTSX