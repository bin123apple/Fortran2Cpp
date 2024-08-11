PROGRAM test_zla_gbrpvgrw
  IMPLICIT NONE
  INTEGER :: n, kl, ku, ncols, ldab, ldafb
  DOUBLE PRECISION :: result
  COMPLEX*16, ALLOCATABLE :: AB(:,:), AFB(:,:)
  
  ! Initialize parameters for the test case
  n = 4
  kl = 1
  ku = 1
  ncols = 4
  ldab = 3
  ldafb = 3

  ! Allocate arrays
  ALLOCATE(AB(ldab, ncols))
  ALLOCATE(AFB(ldafb, ncols))

  ! Fill in AB and AFB with example values for the test
  AB = COMPLEX(1.0D0, 0.0D0)
  AFB = COMPLEX(1.0D0, 0.0D0)

  ! Call the function
  result = ZLA_GBRPVGRW(n, kl, ku, ncols, AB, ldab, AFB, ldafb)

  PRINT *, "Result: ", result

  DEALLOCATE(AB)
  DEALLOCATE(AFB)

CONTAINS

  DOUBLE PRECISION FUNCTION ZLA_GBRPVGRW(N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB)
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N, KL, KU, NCOLS, LDAB, LDAFB
    COMPLEX*16, INTENT(IN) :: AB(LDAB, *), AFB(LDAFB, *)
    INTEGER :: I, J, KD
    DOUBLE PRECISION :: AMAX, UMAX, RPVGRW

    RPVGRW = 1.0D+0
    KD = KU + 1
    DO J = 1, NCOLS
      AMAX = 0.0D+0
      UMAX = 0.0D+0
      DO I = MAX(J-KU, 1), MIN(J+KL, N)
        AMAX = MAX(CABS1(AB(KD+I-J, J)), AMAX)
      END DO
      DO I = MAX(J-KU, 1), J
        UMAX = MAX(CABS1(AFB(KD+I-J, J)), UMAX)
      END DO
      IF (UMAX /= 0.0D+0) THEN
        RPVGRW = MIN(AMAX / UMAX, RPVGRW)
      END IF
    END DO
    ZLA_GBRPVGRW = RPVGRW
  END FUNCTION ZLA_GBRPVGRW

  DOUBLE PRECISION FUNCTION CABS1(Z)
    COMPLEX*16, INTENT(IN) :: Z
    CABS1 = ABS(DBLE(Z)) + ABS(DIMAG(Z))
  END FUNCTION CABS1

END PROGRAM test_zla_gbrpvgrw