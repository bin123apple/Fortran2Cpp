PROGRAM main
  IMPLICIT NONE
  INTEGER, TARGET :: arr(12), basem(3, 4)
  INTEGER, POINTER :: vec(:), mat(:, :)
  INTEGER :: i

  arr = (/ (i, i = 1, 12) /)
  basem = RESHAPE (arr, SHAPE (basem))

  ! Test array initialization
  DO i = 1, 12
    IF (arr(i) /= i) CALL abort()
  END DO

  ! Test array reshaping by checking the first and last elements
  IF (basem(1, 1) /= 1 .OR. basem(3, 4) /= 12) CALL abort ()

  ! Test subsetting with pointers
  vec(2:5) => arr(1:12:2)
  IF (vec(2) /= 1 .OR. vec(5) /= 7) CALL abort()

  ! Test conditional checks
  vec => arr(1:12:2)
  mat(1:3, 1:2) => vec
  IF (mat(1, 1) /= 1 .OR. mat(3, 2) /= 11) CALL abort()

  PRINT *, "All tests passed successfully."
END PROGRAM main