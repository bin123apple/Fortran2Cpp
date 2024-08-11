PROGRAM TestRL
  IMPLICIT NONE
  REAL*8 :: Q, result

  ! Function prototype declaration is not needed for internal functions
  ! defined in the CONTAINS section.

  ! Test case 1
  Q = 8.0
  result = RL(Q)
  PRINT *, 'RL(', Q, ') = ', result

  ! Test case 2
  Q = 1.0
  result = RL(Q)
  PRINT *, 'RL(', Q, ') = ', result
  
  ! Add more test cases as needed

CONTAINS

  REAL*8 FUNCTION RL(Q)
    REAL*8, INTENT(IN) :: Q
    REAL*8 :: P

    P = Q**(1.d0/3.d0)
    RL = 0.49d0 * P * P / (0.6d0 * P * P + LOG(1.d0 + P))

  END FUNCTION RL

END PROGRAM TestRL