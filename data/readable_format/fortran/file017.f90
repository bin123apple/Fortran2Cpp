MODULE H5Z
    IMPLICIT NONE
CONTAINS
    SUBROUTINE h5zunregister_f(filter, hdferr)
        INTEGER, INTENT(IN) :: filter
        INTEGER, INTENT(OUT) :: hdferr
        hdferr = 0  ! Mock success
    END SUBROUTINE h5zunregister_f

    SUBROUTINE h5zfilter_avail_f(filter, status, hdferr)
        INTEGER, INTENT(IN) :: filter
        LOGICAL, INTENT(OUT) :: status
        INTEGER, INTENT(OUT) :: hdferr
        hdferr = 0  ! Mock success
        status = .TRUE.
    END SUBROUTINE h5zfilter_avail_f

    SUBROUTINE h5zget_filter_info_f(filter, config_flags, hdferr)
        INTEGER, INTENT(IN) :: filter
        INTEGER, INTENT(OUT) :: config_flags
        INTEGER, INTENT(OUT) :: hdferr
        hdferr = 0  ! Mock success
        config_flags = 2
    END SUBROUTINE h5zget_filter_info_f
END MODULE H5Z

PROGRAM test
    USE H5Z
    IMPLICIT NONE
    INTEGER :: hdferr, filter, config_flags
    LOGICAL :: status

    filter = 1
    CALL h5zunregister_f(filter, hdferr)
    PRINT *, "h5zunregister_f Error Code:", hdferr

    CALL h5zfilter_avail_f(filter, status, hdferr)
    PRINT *, "h5zfilter_avail_f Status:", status, "Error Code:", hdferr

    CALL h5zget_filter_info_f(filter, config_flags, hdferr)
    PRINT *, "h5zget_filter_info_f Config Flags:", config_flags, "Error Code:", hdferr
END PROGRAM test