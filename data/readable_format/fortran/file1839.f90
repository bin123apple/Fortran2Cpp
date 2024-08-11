MODULE GET_SLICE_NUMBER__genmod
  IMPLICIT NONE
CONTAINS
  FUNCTION GET_SLICE_NUMBER(ICHUNK,IXI,IETA,NPROC_XI,NPROC_ETA) RESULT(slice_number)
    INTEGER(KIND=4), INTENT(IN) :: ICHUNK, IXI, IETA, NPROC_XI, NPROC_ETA
    INTEGER(KIND=4) :: slice_number
    ! Example implementation - replace with actual logic
    slice_number = (ICHUNK * NPROC_XI * NPROC_ETA) + (IXI * NPROC_ETA) + IETA
  END FUNCTION GET_SLICE_NUMBER
END MODULE GET_SLICE_NUMBER__genmod

PROGRAM test_slice_number
  USE GET_SLICE_NUMBER__genmod
  IMPLICIT NONE
  INTEGER(KIND=4) :: result

  ! Test Case 1
  result = GET_SLICE_NUMBER(1, 2, 3, 4, 5)
  PRINT *, "Test Case 1 Result: ", result
  ! Add additional test cases as needed

END PROGRAM test_slice_number