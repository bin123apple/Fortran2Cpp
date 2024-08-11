MODULE mock_mpi
  IMPLICIT NONE
  INTEGER, PARAMETER :: MPI_COMM_WORLD=0, MPI_INTEGER=4, MPI_REAL=4
  INTEGER, PARAMETER :: MPI_SUCCESS=0
  INTEGER :: MPI_STATUS_SIZE=1
  INTEGER :: mpi_mod_dummy=0 ! Dummy variable to avoid unused warnings

CONTAINS

  SUBROUTINE MPI_INIT(ierr)
    INTEGER, INTENT(OUT) :: ierr
    ierr = MPI_SUCCESS
    PRINT *, "MPI_INIT called (mock)"
  END SUBROUTINE MPI_INIT

  SUBROUTINE MPI_FINALIZE(ierr)
    INTEGER, INTENT(OUT) :: ierr
    ierr = MPI_SUCCESS
    PRINT *, "MPI_FINALIZE called (mock)"
  END SUBROUTINE MPI_FINALIZE

  SUBROUTINE MPI_COMM_RANK(comm, rank, ierr)
    INTEGER, INTENT(IN) :: comm
    INTEGER, INTENT(OUT) :: rank, ierr
    rank = 0
    ierr = MPI_SUCCESS
    PRINT *, "MPI_COMM_RANK called (mock)"
  END SUBROUTINE MPI_COMM_RANK

  SUBROUTINE MPI_COMM_SIZE(comm, size, ierr)
    INTEGER, INTENT(IN) :: comm
    INTEGER, INTENT(OUT) :: size, ierr
    size = 1
    ierr = MPI_SUCCESS
    PRINT *, "MPI_COMM_SIZE called (mock)"
  END SUBROUTINE MPI_COMM_SIZE

  ! Add more dummy MPI procedures as needed
END MODULE mock_mpi

PROGRAM main
  USE mock_mpi
  IMPLICIT NONE
  INTEGER :: ierr

  CALL MPI_INIT(ierr)
  ! Your program's logic here, using the mock MPI module
  CALL MPI_FINALIZE(ierr)
END PROGRAM main