PROGRAM TestBININT
    IMPLICIT NONE
    INTEGER*2 IA(10, 10)
    DOUBLE PRECISION X(100), Y(100), Z(100), W(100)
    INTEGER NBIN, NPIX, NLINES, INVAL, IDX, IDY, I, J

    NPIX = 10
    NLINES = 10
    INVAL = 0
    IDX = 2
    IDY = 2

    ! Initialize IA with some data
    DO J = 1, NLINES
        DO I = 1, NPIX
            IA(I, J) = I + J
        ENDDO
    ENDDO

    CALL BININT(IA, NPIX, NLINES, INVAL, IDX, IDY, X, Y, Z, W, NBIN)

    PRINT*, 'NBIN = ', NBIN
    DO I = 1, NBIN
        PRINT*, 'X(', I, ') = ', X(I), ', Y(', I, ') = ', Y(I), ', Z(', I, ') = ', Z(I), ', W(', I, ') = ', W(I)
    ENDDO

CONTAINS

    SUBROUTINE BININT(IA,NPIX,NLINES,INVAL,IDX,IDY,X,Y,Z,W,NBIN)
        INTEGER*2 IA(NPIX,NLINES)
        DOUBLE PRECISION X(*),Y(*),Z(*),W(*)
        INTEGER NBIN, NPIX, NLINES, INVAL, IDX, IDY, JMIN, JMAX, IMIN, IMAX, NPT, IX, IY, I, J
        DOUBLE PRECISION SUM

        NBIN=0
        DO JMIN=1,NLINES,IDY
            JMAX=MIN(JMIN+IDY-1,NLINES)
            DO IMIN=1,NPIX,IDX
                IMAX=MIN(IMIN+IDX-1,NPIX)
                SUM=0.0D0
                NPT=0
                IX=0
                IY=0
                DO J=JMIN,JMAX
                    DO I=IMIN,IMAX
                        IF(IA(I,J).NE.INVAL) THEN
                            SUM=SUM+IA(I,J)
                            NPT=NPT+1
                            IX=IX+I
                            IY=IY+J
                        ENDIF
                    ENDDO
                ENDDO
                IF(NPT.GE.1) THEN
                    NBIN=NBIN+1
                    X(NBIN)=DBLE(IX)/DBLE(NPT)
                    Y(NBIN)=DBLE(IY)/DBLE(NPT)
                    Z(NBIN)=SUM/DBLE(NPT)
                    W(NBIN)=DSQRT(DBLE(NPT))
                ENDIF
            ENDDO
        ENDDO
    END SUBROUTINE BININT

END PROGRAM TestBININT