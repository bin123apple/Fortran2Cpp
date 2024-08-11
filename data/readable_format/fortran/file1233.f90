PROGRAM testCKSTRT
    IMPLICIT NONE
    INTEGER NMM, NKK, NII, MXSP, MXTB, MXTP, NCP, NCP1
    INTEGER NCP2, NCP2T, NPAR, NLAR, NFAR, NLAN, NFAL, NREV
    INTEGER NTHB, NRLT, NWL, NRNU, NORD, MXORD, IcMM, IcKK
    INTEGER IcNC, IcPH, IcCH, IcNT, IcNU, IcNK, IcNS, IcNR
    INTEGER IcLT, IcRL, IcRV, IcWL, IcFL, IcFO, IcKF, IcTB
    INTEGER IcKN, IcKT, IcRNU, IcORD, IcKOR, NcAW, NcWT, NcTT
    INTEGER NcAA, NcCO, NcRV, NcLT, NcRL, NcFL, NcKT, NcWL
    INTEGER NcRU, NcRC, NcPA, NcKF, NcKR, NcRNU, NcKOR, NcK1
    INTEGER NcK2, NcK3, NcK4, NcI1, NcI2, NcI3, NcI4

    COMMON /CKSTRT/ NMM, NKK, NII, MXSP, MXTB, MXTP, NCP, NCP1, &
                     NCP2, NCP2T, NPAR, NLAR, NFAR, NLAN, NFAL, NREV, &
                     NTHB, NRLT, NWL, NRNU, NORD, MXORD, IcMM, IcKK, &
                     IcNC, IcPH, IcCH, IcNT, IcNU, IcNK, IcNS, IcNR, &
                     IcLT, IcRL, IcRV, IcWL, IcFL, IcFO, IcKF, IcTB, &
                     IcKN, IcKT, IcRNU, IcORD, IcKOR, NcAW, NcWT, NcTT, &
                     NcAA, NcCO, NcRV, NcLT, NcRL, NcFL, NcKT, NcWL, &
                     NcRU, NcRC, NcPA, NcKF, NcKR, NcRNU, NcKOR, NcK1, &
                     NcK2, NcK3, NcK4, NcI1, NcI2, NcI3, NcI4

    ! Initialize variables
    NMM = 1
    NKK = 2
    ! Test access and modification
    NMM = NMM + 1
    IF (NMM /= 2) THEN
        PRINT *, 'Test Failed for NMM'
    ELSE
        PRINT *, 'Test Passed for NMM'
    END IF

    ! Continue with similar tests for other variables
    
END PROGRAM testCKSTRT