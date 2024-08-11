PROGRAM TestIZMAX1
  IMPLICIT NONE
  COMPLEX*16, ALLOCATABLE :: CX(:)
  INTEGER :: N, INCX, RESULT

  ! Test 1: Single-element array
  ALLOCATE(CX(1))
  CX(1) = (1.0D0, 2.0D0)
  N = 1
  INCX = 1
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 1 (Single-element array): Expected 1, got", RESULT

  ! Test 2: Multi-element array, INCX = 1
  ALLOCATE(CX(3))
  CX = [(2.0D0, 2.0D0), (3.0D0, 4.0D0), (1.0D0, 1.0D0)]
  N = 3
  INCX = 1
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 2 (Multi-element, INCX=1): Expected 2, got", RESULT

  ! Test 3: Multi-element array, INCX > 1
  N = 3
  INCX = 2
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 3 (Multi-element, INCX>1): Expected 1, got", RESULT

  ! Test 4: Empty array
  N = 0
  INCX = 1
  RESULT = IZMAX1(N, CX, INCX)
  PRINT *, "Test 4 (Empty array): Expected 0, got", RESULT

  CONTAINS

  INTEGER FUNCTION IZMAX1(N, CX, INCX)
    INTEGER, INTENT(IN) :: N, INCX
    COMPLEX*16, INTENT(IN) :: CX(*)
    REAL :: SMAX
    INTEGER :: I, IX
    COMPLEX*16 :: ZDUM

    IZMAX1 = 0
    IF (N < 1) RETURN
    IZMAX1 = 1
    IF (N == 1) RETURN

    SMAX = ABS(CX(1))
    IF (INCX == 1) THEN
      DO I = 2, N
        IF (ABS(CX(I)) > SMAX) THEN
          IZMAX1 = I
          SMAX = ABS(CX(I))
        END IF
      END DO
    ELSE
      IX = 1
      DO I = 2, N
        IX = IX + INCX
        IF (ABS(CX(IX)) > SMAX) THEN
          IZMAX1 = I
          SMAX = ABS(CX(IX))
        END IF
      END DO
    END IF
  END FUNCTION IZMAX1

END PROGRAM TestIZMAX1