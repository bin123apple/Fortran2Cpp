SUBROUTINE def_error
      RETURN
END SUBROUTINE def_error

PROGRAM test_def_error
      CALL def_error
      PRINT *, 'def_error subroutine was called successfully.'
END PROGRAM test_def_error