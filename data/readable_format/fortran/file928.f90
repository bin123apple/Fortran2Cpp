PROGRAM testZMLT
  IMPLICIT NONE

  DOUBLE PRECISION AR, AI, BR, BI, CR, CI

  CALL test(1.0D0, 2.0D0, 3.0D0, 4.0D0, -5.0D0, 10.0D0)
  CALL test(-1.0D0, -2.0D0, -3.0D0, -4.0D0, -5.0D0, 10.0D0)
  CALL test(-1.0D0, 2.0D0, 3.0D0, -4.0D0, 5.0D0, -10.0D0)
  CALL test(0.0D0, 0.0D0, 3.0D0, 4.0D0, 0.0D0, 0.0D0)

END PROGRAM testZMLT

SUBROUTINE ZMLT (AR, AI, BR, BI, CR, CI)
  DOUBLE PRECISION AR, AI, BR, BI, CR, CI, CA, CB
  CA = AR*BR - AI*BI
  CB = AR*BI + AI*BR
  CR = CA
  CI = CB
END SUBROUTINE ZMLT

SUBROUTINE test(ar, ai, br, bi, expected_cr, expected_ci)
  DOUBLE PRECISION AR, AI, BR, BI, CR, CI
  DOUBLE PRECISION expected_cr, expected_ci
  CALL ZMLT(ar, ai, br, bi, CR, CI)
  IF (CR == expected_cr .AND. CI == expected_ci) THEN
    PRINT *, "Test passed."
  ELSE
    PRINT *, "Test failed."
  ENDIF
END SUBROUTINE test