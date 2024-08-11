! File: test_parallel_include.f90
PROGRAM test_parallel_include
    ! Simulated parallel_include module content
    LOGICAL :: tparallel
    
    ! Simulating the effect of a compilation flag
    ! In real application, this would be determined by a preprocessor or build configuration.
    tparallel = .FALSE.
    
    ! Check the value of tparallel to determine if MPI is considered enabled
    IF (tparallel) THEN
        PRINT *, "MPI is enabled (tparallel is TRUE)."
    ELSE
        PRINT *, "MPI is not enabled (tparallel is FALSE)."
    END IF
END PROGRAM test_parallel_include