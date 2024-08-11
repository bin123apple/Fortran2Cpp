PROGRAM main
  IMPLICIT NONE
  INTEGER :: nqp, info, rule

  ! Define dummy rule constants
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_center = 1
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_nodes = 2
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_edges = 3
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_cne = 4
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_stroud = 5
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_hammer7 = 6
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_hammer3 = 7
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_hammer4 = 8
  INTEGER, PARAMETER :: ppm_param_bem_quadrule_hammer12 = 9

  ! Define error codes
  INTEGER, PARAMETER :: ppm_error_success = 0
  INTEGER, PARAMETER :: ppm_error_error = -1

  ! Example usage: Call the subroutine with a known rule
  rule = ppm_param_bem_quadrule_center
  CALL ppm_bem_quadrule_npoints(rule, nqp, info)
  PRINT *, 'Rule:', rule, ' -> NQP:', nqp, ', Info:', info

  ! Test with an unknown rule
  rule = -1
  CALL ppm_bem_quadrule_npoints(rule, nqp, info)
  PRINT *, 'Rule:', rule, ' -> NQP:', nqp, ', Info:', info

CONTAINS

  SUBROUTINE ppm_bem_quadrule_npoints(rule, nqp, info)
    INTEGER, INTENT(IN) :: rule
    INTEGER, INTENT(OUT) :: nqp
    INTEGER, INTENT(OUT) :: info
    ! Assume success initially
    info = ppm_error_success

    SELECT CASE (rule)
    CASE (ppm_param_bem_quadrule_center)
       nqp = 1
    CASE (ppm_param_bem_quadrule_nodes, ppm_param_bem_quadrule_edges, ppm_param_bem_quadrule_hammer3)
       nqp = 3
    CASE (ppm_param_bem_quadrule_cne, ppm_param_bem_quadrule_stroud, ppm_param_bem_quadrule_hammer7)
       nqp = 7
    CASE (ppm_param_bem_quadrule_hammer4)
       nqp = 4
    CASE (ppm_param_bem_quadrule_hammer12)
       nqp = 12
    CASE DEFAULT
       nqp = 0
       info = ppm_error_error ! Unknown rule
       PRINT *, 'Error: Unknown quadrature rule.'
    END SELECT
  END SUBROUTINE ppm_bem_quadrule_npoints

END PROGRAM main