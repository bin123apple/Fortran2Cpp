PROGRAM test_indxg2l
    INTEGER :: result

    ! Test case 1
    result = INDXG2L(10, 4, 1, 0, 5)
    PRINT *, 'Test case 1: ', result  ! Expected output: 2

    ! Test case 2
    result = INDXG2L(20, 4, 2, 0, 5)
    PRINT *, 'Test case 2: ', result  ! Expected output: 4

    ! Test case 3
    result = INDXG2L(15, 3, 1, 0, 4)
    PRINT *, 'Test case 3: ', result  ! Expected output: 6

    ! Test case 4
    result = INDXG2L(1, 2, 0, 0, 3)
    PRINT *, 'Test case 4: ', result  ! Expected output: 1

    ! Test case 5
    result = INDXG2L(25, 5, 3, 0, 6)
    PRINT *, 'Test case 5: ', result  ! Expected output: 5

END PROGRAM test_indxg2l

INTEGER FUNCTION INDXG2L(INDXGLOB, NB, IPROC, ISRCPROC, NPROCS)
    INTEGER, INTENT(IN) :: INDXGLOB, NB, IPROC, ISRCPROC, NPROCS
    INTRINSIC MOD

    INDXG2L = NB * ((INDXGLOB - 1) / (NB * NPROCS)) + MOD(INDXGLOB - 1, NB) + 1
END FUNCTION INDXG2L