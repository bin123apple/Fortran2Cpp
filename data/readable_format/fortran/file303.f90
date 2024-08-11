MODULE n_layers
    IMPLICIT NONE
CONTAINS
    FUNCTION calculate_layers(x) RESULT(y)
        INTEGER, INTENT(IN) :: x
        INTEGER :: y
        ! Example functionality
        y = x * 2
    END FUNCTION calculate_layers
END MODULE n_layers

PROGRAM test_n_layers
    USE n_layers
    IMPLICIT NONE
    INTEGER :: test_input
    INTEGER :: expected_output
    INTEGER :: actual_output

    ! Example test case for calculate_layers function
    test_input = 2
    expected_output = 4
    actual_output = calculate_layers(test_input)

    WRITE(*,*) "Testing calculate_layers with input:", test_input
    WRITE(*,*) "Expected output:", expected_output, "Actual output:", actual_output

    IF (actual_output == expected_output) THEN
        WRITE(*,*) "Test passed."
    ELSE
        WRITE(*,*) "Test failed."
    END IF
END PROGRAM test_n_layers