MODULE ToxicityRelations
    IMPLICIT NONE
    CONTAINS

    SUBROUTINE AddRelationship(less, more, lessToxic, moreToxic, numRelations)
        CHARACTER(len=*), INTENT(IN) :: less, more
        CHARACTER(len=3), DIMENSION(:), INTENT(INOUT) :: lessToxic, moreToxic
        INTEGER, INTENT(INOUT) :: numRelations

        numRelations = numRelations + 1
        lessToxic(numRelations) = less
        moreToxic(numRelations) = more
    END SUBROUTINE AddRelationship

    SUBROUTINE CheckRelationship(less, more, lessToxic, moreToxic, numRelations)
        CHARACTER(len=*), INTENT(IN) :: less, more
        CHARACTER(len=3), DIMENSION(:), INTENT(IN) :: lessToxic, moreToxic
        INTEGER, INTENT(IN) :: numRelations
        INTEGER :: i
        LOGICAL :: found

        found = .FALSE.
        DO i = 1, numRelations
            IF (lessToxic(i) == less .AND. moreToxic(i) == more) THEN
                WRITE(*,*) less, "is less toxic than", more
                found = .TRUE.
                EXIT
            END IF
        END DO

        IF (.NOT. found) THEN
            WRITE(*,*) less, "and", more, "relationship not found."
        END IF
    END SUBROUTINE CheckRelationship

END MODULE ToxicityRelations


PROGRAM ToxicityChecker
    USE ToxicityRelations
    IMPLICIT NONE

    INTEGER, PARAMETER :: maxRelations = 50
    CHARACTER(len=3), DIMENSION(maxRelations) :: lessToxic, moreToxic
    INTEGER :: numRelations

    numRelations = 0
    CALL AddRelationship('q1', 'dd1', lessToxic, moreToxic, numRelations)
    CALL AddRelationship('s1', 'h1', lessToxic, moreToxic, numRelations)
    ! Add other relationships here...

    CALL CheckRelationship('q1', 'dd1', lessToxic, moreToxic, numRelations)
    CALL CheckRelationship('dd1', 'q1', lessToxic, moreToxic, numRelations)
    ! Add other checks here...

END PROGRAM ToxicityChecker