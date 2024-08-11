SUBROUTINE DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX)
    INTEGER            DTRD1, DTRD2, N1, N2
    INTEGER            INDEX(*)
    DOUBLE PRECISION   A(*)
    INTEGER            I, IND1, IND2, N1SV, N2SV
    N1SV = N1
    N2SV = N2
    IF(DTRD1.GT.0) THEN
       IND1 = 1
    ELSE
       IND1 = N1
    END IF
    IF(DTRD2.GT.0) THEN
       IND2 = 1 + N1
    ELSE
       IND2 = N1 + N2
    END IF
    I = 1
    DO WHILE (N1SV.GT.0 .AND. N2SV.GT.0)
       IF(A(IND1).LE.A(IND2)) THEN
          INDEX(I) = IND1
          I = I + 1
          IND1 = IND1 + DTRD1
          N1SV = N1SV - 1
       ELSE
          INDEX(I) = IND2
          I = I + 1
          IND2 = IND2 + DTRD2
          N2SV = N2SV - 1
       END IF
    END DO
    IF(N1SV.EQ.0) THEN
       DO I = I, I + N2SV - 1
          INDEX(I) = IND2
          IND2 = IND2 + DTRD2
       END DO
    ELSE
       DO I = I, I + N1SV - 1
          INDEX(I) = IND1
          IND1 = IND1 + DTRD1
       END DO
    END IF
END SUBROUTINE DLAMRG

PROGRAM TestDLAMRG
    IMPLICIT NONE
    DOUBLE PRECISION, ALLOCATABLE :: A(:)
    INTEGER, ALLOCATABLE :: INDEX(:)
    INTEGER :: N1, N2, DTRD1, DTRD2

    ! Test 1
    N1 = 3
    N2 = 2
    DTRD1 = 1
    DTRD2 = 1
    ALLOCATE(A(N1+N2))
    ALLOCATE(INDEX(N1+N2))
    A = (/1.0, 3.0, 5.0, 2.0, 4.0/)
    CALL DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX)
    PRINT *, 'Test 1: ', INDEX

    ! Test 2
    N1 = 2
    N2 = 3
    DTRD1 = -1
    DTRD2 = -1
    A = (/4.0, 2.0, 5.0, 3.0, 1.0/)
    CALL DLAMRG(N1, N2, A, DTRD1, DTRD2, INDEX)
    PRINT *, 'Test 2: ', INDEX

    DEALLOCATE(A)
    DEALLOCATE(INDEX)
END PROGRAM TestDLAMRG