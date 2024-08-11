PROGRAM TestSLA_GBRPVGRW
  IMPLICIT NONE
  REAL :: result
  INTEGER, PARAMETER :: n = 3, kl = 1, ku = 1, ncols = 3, ldab = 3, ldafb = 3
  REAL, DIMENSION(ldab, ncols) :: AB = RESHAPE( &
       [1.0, 2.0, 0.0, &
        3.0, 4.0, 1.0, &
        0.0, 3.0, 5.0], &
       [ldab, ncols])
  REAL, DIMENSION(ldafb, ncols) :: AFB = RESHAPE( &
       [0.5, 1.0, 0.0, &
        1.5, 2.0, 0.5, &
        0.0, 1.5, 2.5], &
       [ldafb, ncols])

  result = SLA_GBRPVGRW(n, kl, ku, ncols, AB, ldab, AFB, ldafb)
  PRINT *, "Result: ", result

CONTAINS

  REAL FUNCTION SLA_GBRPVGRW( N, KL, KU, NCOLS, AB, LDAB, AFB, LDAFB )
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: N, KL, KU, NCOLS, LDAB, LDAFB
    REAL, INTENT(IN) :: AB( LDAB, * ), AFB( LDAFB, * )
    INTEGER :: I, J, KD
    REAL :: AMAX, UMAX, RPVGRW
    RPVGRW = 1.0
    KD = KU + 1
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
          RPVGRW = MIN( AMAX / UMAX, RPVGRW )
       END IF
    END DO
    SLA_GBRPVGRW = RPVGRW
  END FUNCTION SLA_GBRPVGRW

END PROGRAM TestSLA_GBRPVGRW