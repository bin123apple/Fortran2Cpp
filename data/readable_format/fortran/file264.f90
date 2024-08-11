PROGRAM MB03BATest
  IMPLICIT NONE
  INTEGER, PARAMETER :: K = 5, H = 3
  INTEGER :: S(K) = (/1, 1, -1, 1, 1/)
  INTEGER :: SMULT
  INTEGER :: AMAP(K), QMAP(K)
  INTEGER :: I

  ! Calling the MB03BA subroutine
  CALL MB03BA(K, H, S, SMULT, AMAP, QMAP)

  ! Output the results
  PRINT *, 'SMULT:', SMULT
  PRINT *, 'AMAP:', (AMAP(I), I=1,K)
  PRINT *, 'QMAP:', (QMAP(I), I=1,K)

CONTAINS

  SUBROUTINE MB03BA( K, H, S, SMULT, AMAP, QMAP )
    INTEGER           K, H, SMULT
    INTEGER           AMAP(*), QMAP(*), S(*)
    INTEGER           I, TEMP
    INTRINSIC         MOD

    IF ( S(H).EQ.-1 ) THEN
       SMULT = -1
       DO 10  I = 1, H
          AMAP(I) = H-I+1
10      CONTINUE
       DO 20  I = H+1, K
          AMAP(I) = H+1-I+K
20      CONTINUE
       TEMP = MOD( H, K ) + 1
       DO 30  I = TEMP, 1, -1
          QMAP(TEMP-I+1) = I
30      CONTINUE
       DO 40  I = K, TEMP + 1, -1
          QMAP(TEMP+K-I+1) = I
40      CONTINUE
    ELSE
       SMULT = 1
       DO 50  I = H, K
          AMAP(I-H+1) = I
          QMAP(I-H+1) = I
50      CONTINUE
       DO 60  I = 1, H-1
          AMAP(K-H+I+1) = I
          QMAP(K-H+I+1) = I
60      CONTINUE
    END IF

    RETURN
  END SUBROUTINE MB03BA

END PROGRAM MB03BATest