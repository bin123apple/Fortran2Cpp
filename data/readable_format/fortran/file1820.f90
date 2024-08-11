SUBROUTINE YA0013(IDA,nf1,nf5,nf6)
  INTEGER, INTENT(INOUT) :: IDA(9)
  INTEGER, INTENT(IN) :: nf1, nf5, nf6
  INTEGER :: i
  ! Initialize the array to 1
  DO i = 1, SIZE(IDA)
    IDA(i) = 1
  END DO
  ! Perform bit manipulation
  CALL MVBITS(IDA(nf5), 0, 1, IDA(nf6), 2)
END SUBROUTINE YA0013

PROGRAM TestYA0013
  INTEGER :: ida(9)
  INTEGER :: i
  CALL YA0013(ida,1,5,6)
  
  ! Check results and print the array
  DO i = 1, SIZE(IDA)
    PRINT *, 'IDA(', i, ') = ', IDA(i)
  END DO
END PROGRAM TestYA0013