PROGRAM test_irbit2
  IMPLICIT NONE
  INTEGER :: ISEED, result

  ! Example seed value
  ISEED = 12345

  ! Call the IRBIT2 function and print the result
  result = IRBIT2(ISEED)
  PRINT *, 'Result: ', result
  PRINT *, 'New seed value: ', ISEED

CONTAINS

  FUNCTION IRBIT2(ISEED)
    IMPLICIT NONE
    INTEGER :: IRBIT2
    INTEGER, INTENT(INOUT) :: ISEED
    INTEGER, PARAMETER :: IB1=1, IB2=2, IB5=16, IB18=131072
    INTEGER, PARAMETER :: MASK=IB1+IB2+IB5

    IF (IAND(ISEED, IB18) /= 0) THEN
      ISEED = IOR(ISHFT(IEOR(ISEED, MASK), 1), IB1)
      IRBIT2 = 1
    ELSE
      ISEED = IAND(ISHFT(ISEED, 1), NOT(IB1))
      IRBIT2 = 0
    ENDIF
  END FUNCTION IRBIT2

END PROGRAM test_irbit2