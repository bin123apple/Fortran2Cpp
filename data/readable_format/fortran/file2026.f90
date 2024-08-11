PROGRAM testInitialization
    IMPLICIT NONE
    INTEGER :: ct_lun = 0
    INTEGER :: ion_lun = 0
    INTEGER :: curr_lsf_num = 0
    CHARACTER(len=1) :: sf_name = ' '
    CHARACTER(len=1) :: def_map = ' '
    LOGICAL :: cal_init = .FALSE.
    LOGICAL :: ion_init = .FALSE.
    LOGICAL :: map_init = .FALSE.
    LOGICAL :: rem_init = .FALSE.

    WRITE(*,*) 'Testing initializations...'
    CALL testValue('ct_lun', ct_lun, 0)
    CALL testValue('ion_lun', ion_lun, 0)
    CALL testValue('curr_lsf_num', curr_lsf_num, 0)
    CALL testChar('sf_name', sf_name, ' ')
    CALL testChar('def_map', def_map, ' ')
    CALL testLogical('cal_init', cal_init, .FALSE.)
    CALL testLogical('ion_init', ion_init, .FALSE.)
    CALL testLogical('map_init', map_init, .FALSE.)
    CALL testLogical('rem_init', rem_init, .FALSE.)

END PROGRAM testInitialization

SUBROUTINE testValue(name, actual, expected)
    CHARACTER(len=*), INTENT(IN) :: name
    INTEGER, INTENT(IN) :: actual, expected
    IF (actual /= expected) THEN
        WRITE(*,*) name, ' FAILED: Expected ', expected, ' Got ', actual
    ELSE
        WRITE(*,*) name, ' PASSED'
    END IF
END SUBROUTINE testValue

SUBROUTINE testChar(name, actual, expected)
    CHARACTER(len=*), INTENT(IN) :: name
    CHARACTER(len=1), INTENT(IN) :: actual, expected
    IF (actual /= expected) THEN
        WRITE(*,*) name, ' FAILED: Expected ', expected, ' Got ', actual
    ELSE
        WRITE(*,*) name, ' PASSED'
    END IF
END SUBROUTINE testChar

SUBROUTINE testLogical(name, actual, expected)
    CHARACTER(len=*), INTENT(IN) :: name
    LOGICAL, INTENT(IN) :: actual, expected
    IF (actual .neqv. expected) THEN
        WRITE(*,*) name, ' FAILED: Expected ', expected, ' Got ', actual
    ELSE
        WRITE(*,*) name, ' PASSED'
    END IF
END SUBROUTINE testLogical