PROGRAM TestRandomNumberGenerator
  IMPLICIT NONE
  INTEGER :: i, seed
  REAL*8 :: randomValue

  seed = 123456
  CALL DRNSET(seed)

  DO i = 1, 10
     randomValue = DRN(seed)
     PRINT *, 'Random number', i, ':', randomValue
  END DO

CONTAINS

  SUBROUTINE DRNSET( ISEED )
    IMPLICIT NONE
    INTEGER, INTENT(IN) :: ISEED
    INTEGER :: J
    REAL*8 :: RDM(31), RM1, RM2
    INTEGER :: IA1, IC1, M1, IX1
    INTEGER :: IA2, IC2, M2, IX2
    INTEGER :: IA3, IC3, M3, IX3

    COMMON /RANDM/ RDM, RM1, RM2, IA1, IC1, M1, IX1, IA2, IC2, M2, IX2, IA3, IC3, M3, IX3

    IA1 = 1279
    IC1 = 351762
    M1 = 1664557
    IA2 = 2011
    IC2 = 221592
    M2 = 1048583
    IA3 = 15091
    IC3 = 6171
    M3 = 29201

    IX1 = MOD( ISEED, M1 )
    IX1 = MOD( IA1*IX1+IC1, M1 )
    IX2 = MOD( IX1, M2 )
    IX1 = MOD( IA1*IX1+IC1, M1 )
    IX3 = MOD( IX1, M3 )
    RM1 = 1.0D0 / DBLE(M1)
    RM2 = 1.0D0 / DBLE(M2)
    DO J = 1, 31
       IX1 = MOD( IA1*IX1+IC1, M1 )
       IX2 = MOD( IA2*IX2+IC2, M2 )
       RDM(J) = ( DBLE(IX1) + DBLE(IX2)*RM2 )*RM1
    END DO
  END SUBROUTINE DRNSET

  REAL*8 FUNCTION DRN(ISEED)
    IMPLICIT NONE
    INTEGER, INTENT(INOUT) :: ISEED
    INTEGER :: J
    REAL*8 :: RDM(31), RM1, RM2
    INTEGER :: IA1, IC1, M1, IX1
    INTEGER :: IA2, IC2, M2, IX2
    INTEGER :: IA3, IC3, M3, IX3

    COMMON /RANDM/ RDM, RM1, RM2, IA1, IC1, M1, IX1, IA2, IC2, M2, IX2, IA3, IC3, M3, IX3

    IX1 = MOD( IA1*IX1+IC1, M1 )
    IX2 = MOD( IA2*IX2+IC2, M2 )
    IX3 = MOD( IA3*IX3+IC3, M3 )
    J = 1 + INT((31*IX3)/M3)
    DRN = RDM(J)
    RDM(J) = ( DBLE(IX1) + DBLE(IX2)*RM2 )*RM1

    ISEED = IX1
  END FUNCTION DRN

END PROGRAM TestRandomNumberGenerator