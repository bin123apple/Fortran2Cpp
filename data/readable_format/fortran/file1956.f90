MODULE ppm_module_print_defines
    CONTAINS
    SUBROUTINE ppm_print_defines(result)
        INTEGER, INTENT(OUT) :: result
        result = 42
    END SUBROUTINE ppm_print_defines
END MODULE ppm_module_print_defines

PROGRAM main
    USE ppm_module_print_defines
    IMPLICIT NONE
    INTEGER :: output

    CALL ppm_print_defines(output)
    PRINT *, 'The result from ppm_print_defines is: ', output
END PROGRAM main