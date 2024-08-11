PROGRAM test_sla_gbrpvgrw
  IMPLICIT NONE
  
  REAL, ALLOCATABLE :: AB(:,:), AFB(:,:)
  INTEGER :: N, KL, KU, NCOLS, LDAB, LDAFB
  REAL :: result

  ! Define matrix size and band widths
  N = 4
  KL = 1
  KU = 1
  NCOLS = N
  LDAB = KL + KU + 1
  LDAFB = KL + KU + 1

  ALLOCATE(AB(LDAB, N))
  ALLOCATE(AFB(LDAFB, N))

  ! Populate AB and AFB with some values for testing
  AB = 0.0
  AFB = 0.0
  AB(KL+KU+1,1) = 4.0
  AB(KL+KU,2) = -1.0
  AB(KL+KU+1,2) = 4.0
  AB(KL+KU+2,2) = -1.0
  AB(KL+KU+1,3) = 4.0
  AB(KL+KU+2,3) = -1.0
  AB(KL+KU+1,4) = 4.0

  AFB = AB  ! For simplicity, using the same values

  result = SLA_GBRPVGRW(N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB)

  PRINT *, "Reciprocal Pivot Growth Factor:", result

  DEALLOCATE(AB)
  DEALLOCATE(AFB)

CONTAINS

  REAL FUNCTION SLA_GBRPVGRW( N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB )
    INTEGER, INTENT(IN) :: N, KL, KU, NCOLS, LDAB, LDAFB
    REAL, INTENT(IN) :: AB(LDAB, *), AFB(LDAFB, *)

    INTEGER :: I, J, KD
    REAL :: AMAX, UMAX

    KD = KU + 1
    SLA_GBRPVGRW = 1.0

    DO J = 1, NCOLS
       AMAX = 0.0
       UMAX = 0.0
       DO I = MAX( J-KU, 1 ), MIN( J+KL, N )
          AMAX = MAX( ABS( AB( KD+I-J, J)), AMAX )
       END DO
       DO I = MAX( J-KU, 1 ), J
          UMAX = MAX( ABS( AFB( KD+I-J, J ) ), UMAX )
       END DO
       IF ( UMAX /= 0.0 ) THEN
          SLA_GBRPVGRW = MIN( AMAX / UMAX, SLA_GBRPVGRW )
       END IF
    END DO
  END FUNCTION SLA_GBRPVGRW

END PROGRAM test_sla_gbrpvgrw