! mo_column.f90
MODULE mo_column

CONTAINS

SUBROUTINE compute(nz, q, t, z, nproma)
    INTEGER, INTENT(IN) :: nproma
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:,:)
    REAL, INTENT(INOUT) :: q(:,:)
    REAL, INTENT(INOUT) :: z(1:nproma)
    
    CALL compute_column(nz, q, t, z, nproma=nproma)
END SUBROUTINE compute

SUBROUTINE compute_column(nz, q, t, z, nproma)
    INTEGER, INTENT(IN) :: nproma
    INTEGER, INTENT(IN) :: nz
    REAL, INTENT(INOUT) :: t(:,:)
    REAL, INTENT(INOUT) :: q(:,:)
    REAL, INTENT(INOUT) :: z(1:nproma)
    INTEGER :: k
    REAL :: c
    REAL :: p
    INTEGER :: proma
    
    ! Adjusted loop to start from k = 1 for alignment with C++
    DO proma = 1, nproma, 1
        c = 5.345
        p = c ** (2.0)
        DO k = 1, nz-1, 1  ! Adjusted to nz-1 for correct range
            t(proma, k+1) = c * (k+1)  ! Adjusted index to match C++ logic
            p = t(proma, k+1) + 1.0
            q(proma, k+1) = q(proma, k) + t(proma, k+1) * c  ! Adjusted index to match C++ logic
            IF (p > 2.0) THEN
                q(proma, k+1) = q(proma, k) + t(proma, k+1) * c * 2.0  ! Adjusted index to match C++ logic
            END IF
        END DO
        q(proma, nz) = q(proma, nz) * c
    END DO
END SUBROUTINE compute_column

END MODULE mo_column

PROGRAM test_compute
USE mo_column
IMPLICIT NONE
INTEGER :: nz, nproma, i, j
REAL, ALLOCATABLE :: t(:,:), q(:,:), z(:)

! Initialize parameters
nz = 5
nproma = 3

ALLOCATE(t(nproma, nz))
ALLOCATE(q(nproma, nz))
ALLOCATE(z(nproma))

! Initialize arrays with some values
t = 0.0
q = 1.0
z = 2.0

! Call the subroutine to compute
CALL compute(nz, q, t, z, nproma)

! Print the results
PRINT *, "Array t:"
DO i = 1, nproma
    PRINT *, (t(i, j), j = 1, nz)
END DO

PRINT *, "Array q:"
DO i = 1, nproma
    PRINT *, (q(i, j), j = 1, nz)
END DO

END PROGRAM test_compute