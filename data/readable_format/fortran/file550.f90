program test_program
    implicit none
    INTEGER, PARAMETER :: N = 5
    CHARACTER(LEN=N) :: C(3)
    CHARACTER(LEN=N) :: D
    integer :: i

    D = "a"
    do i=1, 3
        C(i) = "a"
    end do

    do i=1, 3
        PRINT *, TRIM(C(i))
    end do
    PRINT *, TRIM(D)
end program test_program