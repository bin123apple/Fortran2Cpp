PROGRAM ppm_util_invert_list_demo
    IMPLICIT NONE
    INTEGER, DIMENSION(5) :: testArray = (/1, 2, 3, 4, 5/)
    INTEGER, DIMENSION(5) :: invertedArray

    CALL ppm_util_invert_list(testArray, invertedArray)
    CALL print_array(invertedArray)

CONTAINS

    SUBROUTINE ppm_util_invert_list(inputArray, outputArray)
        INTEGER, INTENT(IN) :: inputArray(:)
        INTEGER, INTENT(OUT) :: outputArray(SIZE(inputArray))
        INTEGER :: i

        DO i = 1, SIZE(inputArray)
            outputArray(SIZE(inputArray) - i + 1) = inputArray(i)
        END DO
    END SUBROUTINE ppm_util_invert_list

    SUBROUTINE print_array(array)
        INTEGER, INTENT(IN) :: array(:)
        INTEGER :: i

        DO i = 1, SIZE(array)
            WRITE(*,*) array(i)
        END DO
    END SUBROUTINE print_array

END PROGRAM ppm_util_invert_list_demo