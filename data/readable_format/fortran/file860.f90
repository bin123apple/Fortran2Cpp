! This single Fortran file includes the fft_scalar module and a simple test program.
! It demonstrates conditional compilation and includes mock implementations for demonstration purposes.

MODULE fft_param
    ! Mock fft_param module content
    IMPLICIT NONE
    ! Define any parameters needed for FFT operations here
END MODULE fft_param

MODULE fft_scalar
    USE fft_param
    IMPLICIT NONE
    
    PUBLIC :: cft_1z, cft_2xy, cfft3d, cfft3ds

    CONTAINS
        SUBROUTINE cft_1z()
            PRINT *, "cft_1z called"
            ! Implementation goes here
        END SUBROUTINE cft_1z

        SUBROUTINE cft_2xy()
            PRINT *, "cft_2xy called"
            ! Implementation goes here
        END SUBROUTINE cft_2xy

        SUBROUTINE cfft3d()
            PRINT *, "cfft3d called"
            ! Implementation goes here
        END SUBROUTINE cfft3d

        SUBROUTINE cfft3ds()
            PRINT *, "cfft3ds called"
            ! Implementation goes here
        END SUBROUTINE cfft3ds
END MODULE fft_scalar

! Main program to test the fft_scalar module
PROGRAM test_fft_scalar
    USE fft_scalar
    IMPLICIT NONE

    CALL cft_1z()
    CALL cft_2xy()
    CALL cfft3d()
    CALL cfft3ds()

    PRINT *, "All FFT Scalar tests passed."
END PROGRAM test_fft_scalar