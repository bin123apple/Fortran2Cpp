PROGRAM TEST_ESSAI
  IMPLICIT NONE

  double precision :: APX
  double precision :: AKPX
  integer :: IND
  logical :: ERREUR

  integer :: I
  double precision :: epsilon
  double precision, dimension(28) :: AKP, AP

  ! Initialize variables
  epsilon = 1.0d-12
  IND = 1
  APX = 1.5d0
  ERREUR = .FALSE.

  ! Populate AKP and AP with some test data
  DO I = 1, 28
    AKP(I) = I * 1.0d0
    AP(I) = I * 1.0d0
  END DO

  ! Call the ESSAI subroutine
  CALL ESSAI(APX, AKPX, IND, ERREUR, AKP, AP, epsilon)

  ! Print the results
  IF (ERREUR) THEN
    PRINT *, 'Error: APX is less than 0.'
  ELSE
    PRINT *, 'AKPX: ', AKPX
  END IF

CONTAINS

  SUBROUTINE ESSAI(APX, AKPX, IND, ERREUR, AKP, AP, epsilon)
    double precision, intent(in) :: APX
    double precision, intent(out) :: AKPX
    integer, intent(in) :: IND
    logical, intent(out) :: ERREUR
    double precision, dimension(28), intent(in) :: AKP, AP
    double precision, intent(in) :: epsilon

    integer :: I, IM
    logical :: FIN_TRAITEMENT

    ERREUR = .FALSE.

    IF (IND > 0) THEN
      IF (APX < 0.d0) THEN
        ERREUR = .TRUE.
        RETURN
      END IF
      FIN_TRAITEMENT = .FALSE.
      I = 1
      DO WHILE ((I <= 28) .AND. (.NOT. FIN_TRAITEMENT))

        IF (ABS(APX-AP(I)) <= epsilon) THEN
          AKPX = AKP(I)
          FIN_TRAITEMENT = .TRUE.
        ELSE IF (APX <= AP(I)) THEN
          IM = I - 1
          AKPX = AKP(IM) + (AKP(I)-AKP(IM)) * (APX-AP(IM)) / (AP(I)-AP(IM))
          FIN_TRAITEMENT = .TRUE.
        ELSE
          I = I + 1
        END IF

      END DO
    END IF
  END SUBROUTINE ESSAI

END PROGRAM TEST_ESSAI