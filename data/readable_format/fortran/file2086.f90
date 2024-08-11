MODULE greet_fmt_mod
    IMPLICIT NONE
CONTAINS
    SUBROUTINE printGreeting(part1, part2)
        CHARACTER(len=*), INTENT(IN) :: part1, part2
        PRINT '(A,1X,A)', TRIM(part1), TRIM(part2)
    END SUBROUTINE printGreeting
END MODULE greet_fmt_mod

PROGRAM main
    USE greet_fmt_mod
    IMPLICIT NONE
    CALL printGreeting('Hello,', 'World!')
END PROGRAM main