PROGRAM TestSLAS2
  IMPLICIT NONE
  REAL :: F, G, H, SSMIN, SSMAX

  ! Test 1: All zeros
  CALL Test(0.0, 0.0, 0.0)

  ! Test 2: One significantly larger
  CALL Test(100.0, 0.1, 0.1)

  ! Test 3: Similar magnitude, different signs
  CALL Test(-1.0, 1.0, -1.0)

CONTAINS

  SUBROUTINE Test(F, G, H)
    REAL, INTENT(IN) :: F, G, H
    REAL :: SSMIN, SSMAX
    CALL SLAS2(F, G, H, SSMIN, SSMAX)
    PRINT *, "F=", F, "G=", G, "H=", H
    PRINT *, "SSMIN=", SSMIN, "SSMAX=", SSMAX
    PRINT *, "-------------------"
  END SUBROUTINE Test

  SUBROUTINE SLAS2(F, G, H, SSMIN, SSMAX)
    REAL, INTENT(IN) :: F, G, H
    REAL, INTENT(OUT) :: SSMIN, SSMAX
    REAL :: ZERO, ONE, TWO
    REAL :: AS, AT, AU, C, FA, FHMN, FHMX, GA, HA
    PARAMETER (ZERO=0.0E0, ONE=1.0E0, TWO=2.0E0)
    INTRINSIC ABS, MAX, MIN, SQRT

    FA = ABS(F)
    GA = ABS(G)
    HA = ABS(H)
    FHMN = MIN(FA, HA)
    FHMX = MAX(FA, HA)

    IF (FHMN .EQ. ZERO) THEN
      SSMIN = ZERO
      IF (FHMX .EQ. ZERO) THEN
        SSMAX = GA
      ELSE
        SSMAX = MAX(FHMX, GA) * SQRT(ONE + (MIN(FHMX, GA) / MAX(FHMX, GA))**2)
      END IF
    ELSE
      IF (GA .LT. FHMX) THEN
        AS = ONE + FHMN / FHMX
        AT = (FHMX - FHMN) / FHMX
        AU = (GA / FHMX)**2
        C = TWO / (SQRT(AS*AS + AU) + SQRT(AT*AT + AU))
        SSMIN = FHMN * C
        SSMAX = FHMX / C
      ELSE
        AU = FHMX / GA
        IF (AU .EQ. ZERO) THEN
          SSMIN = (FHMN * FHMX) / GA
          SSMAX = GA
        ELSE
          AS = ONE + FHMN / FHMX
          AT = (FHMX - FHMN) / FHMX
          C = ONE / (SQRT(ONE + (AS*AU)**2) + SQRT(ONE + (AT*AU)**2))
          SSMIN = (FHMN * C) * AU
          SSMIN = SSMIN + SSMIN
          SSMAX = GA / (C + C)
        END IF
      END IF
    END IF
  END SUBROUTINE SLAS2

END PROGRAM TestSLAS2