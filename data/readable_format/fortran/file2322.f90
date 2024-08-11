PROGRAM TEST_SUBTRACT_MEAN_3D
    IMPLICIT NONE
    INTEGER, PARAMETER :: MAXX = 3, MAXY = 3, MAXZ = 3
    INTEGER :: NX, NY, NZ
    REAL :: A_IN(MAXX, MAXY, MAXZ)
    REAL :: A_OUT(MAXX, MAXY, MAXZ)
    REAL :: BADDATA
    INTEGER :: IX, IY, IZ

    NX = 3
    NY = 3
    NZ = 3
    BADDATA = -999.0

    ! Initialize the input array with known values
    DO IZ = 1, NZ
        DO IY = 1, NY
            DO IX = 1, NX
                A_IN(IX, IY, IZ) = REAL(IX + IY + IZ)
            ENDDO
        ENDDO
    ENDDO

    ! Call the subroutine
    CALL SUBTRACT_MEAN_3D(A_IN, MAXX, MAXY, MAXZ, NX, NY, NZ, BADDATA, MAXX, MAXY, MAXZ, A_OUT)

    ! Print the output array
    PRINT *, 'Output array:'
    DO IZ = 1, NZ
        DO IY = 1, NY
            PRINT *, (A_OUT(IX, IY, IZ), IX = 1, NX)
        ENDDO
    ENDDO

END PROGRAM TEST_SUBTRACT_MEAN_3D

SUBROUTINE SUBTRACT_MEAN_3D(A_IN, MAXX_IN, MAXY_IN, MAXZ_IN, NX, NY, NZ, BADDATA, MAXX_OUT, MAXY_OUT, MAXZ_OUT, A_OUT)
    IMPLICIT NONE
    INTEGER::MAXX_IN, MAXY_IN, MAXZ_IN, MAXX_OUT, MAXY_OUT, MAXZ_OUT, NX, NY, NZ, IX, IY, IZ, COUNT
    REAL BADDATA, SUM, MEAN
    REAL A_IN(MAXX_IN, MAXY_IN, MAXZ_IN)
    REAL A_OUT(MAXX_OUT, MAXY_OUT, MAXZ_OUT)
    SUM = 0.
    COUNT = 0
    DO IZ = 1, NZ
        DO IY = 1, NY
            DO IX = 1, NX
                IF(A_IN(IX, IY, IZ) .NE. BADDATA) THEN
                    SUM = SUM + A_IN(IX, IY, IZ)
                    COUNT = COUNT + 1
                END IF
            END DO
        END DO
    END DO
    IF(COUNT .NE. 0) THEN
        MEAN = SUM / FLOAT(COUNT)
    END IF
    DO IZ = 1, NZ
        DO IY = 1, NY
            DO IX = 1, NX
                IF(A_IN(IX, IY, IZ) .NE. BADDATA) THEN
                    A_OUT(IX, IY, IZ) = A_IN(IX, IY, IZ) - MEAN
                ELSE
                    A_OUT(IX, IY, IZ) = BADDATA
                END IF
            END DO
        END DO
    END DO
END SUBROUTINE SUBTRACT_MEAN_3D