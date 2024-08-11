PROGRAM test_movec
    CHARACTER*1 SOURCE(5), DEST(5)
    INTEGER I

    ! Initialize source array
    SOURCE(1) = 'H'
    SOURCE(2) = 'e'
    SOURCE(3) = 'l'
    SOURCE(4) = 'l'
    SOURCE(5) = 'o'

    ! Call MOVEC subroutine to copy characters
    CALL MOVEC(5, SOURCE, DEST)

    ! Display DEST array
    WRITE(*,*) 'DEST array after MOVEC:'
    DO I=1,5
        WRITE(*, '(A)', ADVANCE='NO') DEST(I)
    END DO
    WRITE(*,*) ! Newline

END PROGRAM test_movec

SUBROUTINE MOVEC(N, SOURCE, DEST)
    CHARACTER*1 SOURCE(*), DEST(*)
    INTEGER N, I

    DO 100 I=1,N
        DEST(I) = SOURCE(I)
100 CONTINUE
END