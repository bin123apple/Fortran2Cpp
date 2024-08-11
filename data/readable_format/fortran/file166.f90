MODULE global_vars
  IMPLICIT NONE
  LOGICAL :: use_gpu = .FALSE., noncolin = .FALSE., lspinorb = .FALSE., tqr = .FALSE., spline_ps = .FALSE.
  INTEGER :: nat = 0, nspin = 1, nhm = 0, nsp = 0, nbetam = 0, nwfcm = 0, nqxq, nqx
  REAL :: cell_factor = 1.2, ecutrho = 20.0, qnorm = 1.0, dq = 0.1, ecutwfc = 15.0
  REAL :: lmaxq = 0.0, lmaxkb = 0.0, nh = 0.0
END MODULE global_vars

SUBROUTINE allocate_nlpot
  USE global_vars
  IF (spline_ps .AND. cell_factor <= 1.1) cell_factor = 1.1
  nqxq = INT(((SQRT(ecutrho) + qnorm) / dq + 4) * cell_factor)
  nqx = INT((SQRT(ecutwfc) / dq + 4) * cell_factor)
END SUBROUTINE allocate_nlpot

PROGRAM test_allocate_nlpot
  USE global_vars
  CALL allocate_nlpot
  PRINT *, "Fortran Stdout: nqxq =", nqxq
  PRINT *, "Fortran Stdout: nqx =", nqx
END PROGRAM test_allocate_nlpot