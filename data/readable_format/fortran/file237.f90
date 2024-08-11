MODULE mo_kind
  IMPLICIT NONE
  INTEGER, PARAMETER :: pd = 12
  INTEGER, PARAMETER :: rd = 307
  INTEGER, PARAMETER :: dp = SELECTED_REAL_KIND(pd,rd)
END MODULE mo_kind

PROGRAM test_mo_kind
  USE mo_kind
  IMPLICIT NONE

  WRITE(*,*) 'Testing mo_kind module...'
  WRITE(*,*) 'pd should be 12: ', pd
  WRITE(*,*) 'rd should be 307: ', rd
  WRITE(*,'(A,I0)') 'The kind selected for dp (should match kind of DOUBLE PRECISION) is: ', dp
  
  IF (pd /= 12) THEN
    WRITE(*,*) 'Error: pd does not equal 12'
  ELSE
    WRITE(*,*) 'pd test passed.'
  END IF

  IF (rd /= 307) THEN
    WRITE(*,*) 'Error: rd does not equal 307'
  ELSE
    WRITE(*,*) 'rd test passed.'
  END IF

  ! Assuming SELECTED_REAL_KIND(12, 307) matches DOUBLE PRECISION for simplicity
  IF (dp /= KIND(1.0D0)) THEN
    WRITE(*,*) 'Error: dp kind does not match expected DOUBLE PRECISION kind'
  ELSE
    WRITE(*,*) 'dp kind test passed.'
  END IF
END PROGRAM test_mo_kind