! test_module.f90
MODULE test

   TYPE odbase
      INTEGER :: value
   END TYPE odbase

   INTERFACE odfname
      MODULE PROCEDURE odfamilycname, odfamilycnames
   END INTERFACE

CONTAINS

   SUBROUTINE odfamilycnames(base, nfam, cnames)
      TYPE(odbase), INTENT(in) :: base
      INTEGER, INTENT(out) :: nfam
      CHARACTER(*), INTENT(out) :: cnames(*)
      cnames(1:nfam) = 'odfamilycnames'
   END SUBROUTINE odfamilycnames

   SUBROUTINE odfamilycname(base, pos, cname)
      TYPE(odbase), INTENT(in) :: base
      INTEGER, INTENT(in) :: pos
      CHARACTER(*), INTENT(out) :: cname
      cname = 'odfamilycname'
   END SUBROUTINE odfamilycname

END MODULE test

PROGRAM main
  USE test
  TYPE(odbase) :: base
  INTEGER :: i = 1, nfam = 1
  CHARACTER(14) :: cname
  CHARACTER(14) :: cnames(1)
  
  CALL odfname(base, i, cname)
  IF (TRIM(cname) /= "odfamilycname") CALL abort_test()
  
  CALL odfname(base, nfam, cnames)
  IF (TRIM(cnames(1)) /= "odfamilycnames") CALL abort_test()
  
  PRINT *, "All tests passed!"

CONTAINS

  SUBROUTINE abort_test()
    PRINT *, "Test failed!"
    ERROR STOP
  END SUBROUTINE abort_test

END PROGRAM main