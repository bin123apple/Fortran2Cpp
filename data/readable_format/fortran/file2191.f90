PROGRAM TestNUMROC
    INTEGER :: result

    ! Test case 1
    result = NUMROC(100, 10, 0, 0, 4)
    PRINT *, 'Test case 1: ', result
    ! Expected result: 30

    ! Test case 2
    result = NUMROC(100, 10, 1, 0, 4)
    PRINT *, 'Test case 2: ', result
    ! Expected result: 30

    ! Test case 3
    result = NUMROC(100, 10, 2, 0, 4)
    PRINT *, 'Test case 3: ', result
    ! Expected result: 20

    ! Test case 4
    result = NUMROC(100, 10, 3, 0, 4)
    PRINT *, 'Test case 4: ', result
    ! Expected result: 20

END PROGRAM TestNUMROC

INTEGER FUNCTION NUMROC( N, NB, IPROC, ISRCPROC, NPROCS )
    INTEGER              IPROC, ISRCPROC, N, NB, NPROCS
    INTEGER              EXTRABLKS, MYDIST, NBLOCKS
    INTRINSIC            MOD
    MYDIST = MOD( NPROCS+IPROC-ISRCPROC, NPROCS )
    NBLOCKS = N / NB
    NUMROC = (NBLOCKS/NPROCS) * NB
    EXTRABLKS = MOD( NBLOCKS, NPROCS )
    IF( MYDIST.LT.EXTRABLKS ) THEN
        NUMROC = NUMROC + NB
    ELSE IF( MYDIST.EQ.EXTRABLKS ) THEN
        NUMROC = NUMROC + MOD( N, NB )
    END IF
    RETURN
END