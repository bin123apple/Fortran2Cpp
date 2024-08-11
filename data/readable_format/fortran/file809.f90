MODULE PERMUTE_ELEMENTS_LOGICAL1D__genmod
    CONTAINS
    SUBROUTINE PERMUTE_ELEMENTS_LOGICAL1D(ARRAY_TO_PERMUTE, TEMP_ARRAY, PERM, NSPEC)
        INTEGER(KIND=4), INTENT(IN) :: NSPEC
        LOGICAL(KIND=4), INTENT(INOUT) :: ARRAY_TO_PERMUTE(NSPEC)
        LOGICAL(KIND=4), INTENT(INOUT) :: TEMP_ARRAY(NSPEC)
        INTEGER(KIND=4), INTENT(IN) :: PERM(NSPEC)
        INTEGER :: i
        DO i = 1, NSPEC
            TEMP_ARRAY(i) = ARRAY_TO_PERMUTE(PERM(i))
        END DO
        ARRAY_TO_PERMUTE = TEMP_ARRAY
    END SUBROUTINE PERMUTE_ELEMENTS_LOGICAL1D
END MODULE PERMUTE_ELEMENTS_LOGICAL1D__genmod

PROGRAM test_permute
    USE PERMUTE_ELEMENTS_LOGICAL1D__genmod
    IMPLICIT NONE
    INTEGER, PARAMETER :: nSpec = 4
    LOGICAL(KIND=4) :: arrayToPermute(nSpec) = [ .TRUE., .FALSE., .TRUE., .FALSE. ]
    LOGICAL(KIND=4) :: tempArray(nSpec)
    INTEGER :: perm(nSpec)
    INTEGER :: i

    ! Test 1: Reverse permutation
    perm = [ 4, 3, 2, 1 ] ! Reverse
    CALL PERMUTE_ELEMENTS_LOGICAL1D(arrayToPermute, tempArray, perm, nSpec)
    PRINT *, "Test 1: Reverse Permutation"
    DO i = 1, nSpec
        PRINT *, arrayToPermute(i)
    END DO

    ! Reset arrayToPermute for next test
    arrayToPermute = [ .TRUE., .FALSE., .TRUE., .FALSE. ]

    ! Test 2: Custom permutation
    perm = [ 2, 1, 4, 3 ]
    CALL PERMUTE_ELEMENTS_LOGICAL1D(arrayToPermute, tempArray, perm, nSpec)
    PRINT *, "Test 2: Custom Permutation"
    DO i = 1, nSpec
        PRINT *, arrayToPermute(i)
    END DO

    ! Additional tests can be designed with arrays of different sizes
    ! by creating separate programs or modules for each specific scenario.

END PROGRAM test_permute