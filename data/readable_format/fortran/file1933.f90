! combined.f90
MODULE constants

  IMPLICIT NONE

  INTEGER, PARAMETER :: nb_nodes = 9
  INTEGER, PARAMETER :: nb_edges = 8

  CHARACTER(LEN = 4), PARAMETER :: it_max_fmt = "(I4)"

  INTEGER, PARAMETER :: NODE_PIP3 = 1
  INTEGER, PARAMETER :: NODE_PIP2 = 2
  INTEGER, PARAMETER :: NODE_PI3K = 3
  INTEGER, PARAMETER :: NODE_Insulin_receptor_substrat_1 = 4
  INTEGER, PARAMETER :: NODE_Insulin_like_GF1_receptor = 5
  INTEGER, PARAMETER :: NODE_Insulin_receptor = 6
  INTEGER, PARAMETER :: NODE_Insulin_like_growth_factor_1 = 7
  INTEGER, PARAMETER :: NODE_Insulin = 8
  INTEGER, PARAMETER :: NODE_anti_PI3K = 9

  INTEGER, PARAMETER :: EDGE_PIP2__PIP3 = 1
  INTEGER, PARAMETER :: EDGE_PI3K__PIP2 = 2
  INTEGER, PARAMETER :: EDGE_Insulin_receptor_substrat_1__PI3K = 3
  INTEGER, PARAMETER :: EDGE_anti_PI3K__PI3K = 4
  INTEGER, PARAMETER :: EDGE_Insulin_receptor__Insulin_receptor_substrat_1 = 5
  INTEGER, PARAMETER :: EDGE_Insulin_like_GF1_receptor__Insulin_receptor_substrat_1 = 6
  INTEGER, PARAMETER :: EDGE_Insulin_like_growth_factor_1__Insulin_like_GF1_receptor = 7
  INTEGER, PARAMETER :: EDGE_Insulin__Insulin_receptor = 8

END MODULE constants

PROGRAM testConstants
  USE constants
  IMPLICIT NONE

  ! Test a few constants
  IF (nb_nodes /= 9) THEN
    PRINT *, "Test failed for nb_nodes"
  ELSE
    PRINT *, "Test passed for nb_nodes"
  END IF

  IF (NODE_PIP3 /= 1) THEN
    PRINT *, "Test failed for NODE_PIP3"
  ELSE
    PRINT *, "Test passed for NODE_PIP3"
  END IF

  ! Add more tests as needed for other constants...
  
END PROGRAM testConstants