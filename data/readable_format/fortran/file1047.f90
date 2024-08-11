PROGRAM TestSNCNDN
        IMPLICIT NONE
        DOUBLE PRECISION SN, CN, DN, UU, EMMC
        INTEGER I

        ! Define test cases as arrays of UU and EMMC values
        DOUBLE PRECISION, DIMENSION(3) :: UU_TEST = (/0.0, 1.0, 1.57/)
        DOUBLE PRECISION, DIMENSION(3) :: EMMC_TEST = (/0.0, 0.5, -0.5/)

        DO I = 1, 3
            UU = UU_TEST(I)
            EMMC = EMMC_TEST(I)
            CALL SNCNDN(UU, EMMC, SN, CN, DN)
            PRINT *, 'Test Case: ', I
            PRINT *, 'UU = ', UU, ' EMMC = ', EMMC
            PRINT *, 'SN = ', SN, ' CN = ', CN, ' DN = ', DN
            PRINT *, '---------------------------'
        END DO

        END PROGRAM TestSNCNDN

        SUBROUTINE SNCNDN(UU, EMMC, SN, CN, DN)
            IMPLICIT NONE
            DOUBLE PRECISION UU, EMMC, SN, CN, DN
            DOUBLE PRECISION CA, EMC, U, D, A, C, B
            PARAMETER (CA=.0003)
            LOGICAL BO
            DOUBLE PRECISION EM(13), EN(13)
            INTEGER I, L, II

            EMC=EMMC
            U=UU
            IF (EMC .NE. 0.0) THEN
                BO=(EMC .LT. 0.0)
                IF (BO) THEN
                    D=1.0-EMC
                    EMC=-EMC/D
                    D=SQRT(D)
                    U=D*U
                ENDIF
                A=1.0
                DN=1.0
                DO I=1,13
                    L=I
                    EM(I)=A
                    EMC=SQRT(EMC)
                    EN(I)=EMC
                    C=0.5*(A+EMC)
                    IF (ABS(A-EMC) .LE. CA*A) EXIT
                    EMC=A*EMC
                    A=C
                END DO
                U=C*U
                SN=SIN(U)
                CN=COS(U)
                IF (SN .NE. 0) THEN
                    A=CN/SN
                    C=A*C
                    DO II=L,1,-1
                        B=EM(II)
                        A=C*A
                        C=DN*C
                        DN=(EN(II)+A)/(B+A)
                        A=C/B
                    END DO
                    A=1.0/SQRT(C*C+1.0)
                    IF (SN .LT. 0.0) SN=-A
                    IF (SN .GE. 0.0) SN=A
                    CN=C*SN
                ENDIF
                IF (BO) THEN
                    A=DN
                    DN=CN
                    CN=A
                    SN=SN/D
                ENDIF
            ELSE
                CN=1.0/COSH(U)
                DN=CN
                SN=TANH(U)
            ENDIF
        END SUBROUTINE SNCNDN