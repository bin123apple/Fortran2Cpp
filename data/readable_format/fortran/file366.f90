PROGRAM testUDS_SPEC_COPY
    IMPLICIT NONE

    TYPE UDS_SPEC
        INTEGER :: field1
        REAL :: field2
    END TYPE UDS_SPEC

    TYPE(UDS_SPEC) :: sourceSpec, destSpec

    ! Initialize sourceSpec with example values
    sourceSpec%field1 = 1
    sourceSpec%field2 = 2.0

    ! Initialize destSpec with different values
    destSpec%field1 = 0
    destSpec%field2 = 0.0

    ! Call the subroutine to copy sourceSpec to destSpec
    CALL UDS_SPEC_COPY(destSpec, sourceSpec)

    ! Check the results
    IF (destSpec%field1 == sourceSpec%field1 .AND. &
        destSpec%field2 == sourceSpec%field2) THEN
        PRINT *, 'Test Passed.'
    ELSE
        PRINT *, 'Test Failed.'
    END IF

CONTAINS

    SUBROUTINE UDS_SPEC_COPY(D, S)
        TYPE(UDS_SPEC), INTENT(OUT) :: D
        TYPE(UDS_SPEC), INTENT(IN) :: S

        D = S
    END SUBROUTINE UDS_SPEC_COPY

END PROGRAM testUDS_SPEC_COPY