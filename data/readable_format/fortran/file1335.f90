PROGRAM HelloWorldTest
    IMPLICIT NONE

    ! This subroutine prints "Hello, world!"
    CALL PrintHelloWorld

    ! Here, we would typically call a testing subroutine if we had a more complex scenario.
    ! For this simple example, the output itself acts as the "test".

CONTAINS

    ! This subroutine does the actual printing
    SUBROUTINE PrintHelloWorld
        IMPLICIT NONE
        PRINT *, 'Hello, world!'
    END SUBROUTINE PrintHelloWorld

END PROGRAM HelloWorldTest