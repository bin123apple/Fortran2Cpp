PROGRAM test_mp_bcast_im
    IMPLICIT NONE
    INTEGER :: im(10, 10)
    INTEGER :: i, j

    ! Initialize the array
    DO i = 1, 10
        DO j = 1, 10
            im(i, j) = i * j
        END DO
    END DO

    ! Print the array
    CALL print_array(im)
    
CONTAINS

    SUBROUTINE print_array(arr)
        INTEGER, DIMENSION(:,:), INTENT(IN) :: arr
        INTEGER :: i, j

        PRINT *, "Array Contents:"
        DO i = 1, SIZE(arr, 1)
            DO j = 1, SIZE(arr, 2)
                WRITE(*, "(I4)", ADVANCE="NO") arr(i, j)
            END DO
            PRINT *, ""
        END DO
    END SUBROUTINE print_array

END PROGRAM test_mp_bcast_im