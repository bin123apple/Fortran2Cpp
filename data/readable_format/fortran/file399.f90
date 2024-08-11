PROGRAM testCASP_WSP
      INTEGER WSL, BP
      COMMON /CASP_WSP/WSL, BP
      SAVE /CASP_WSP/
      DATA WSL,BP/-1,-1/

      CALL TestInitialization()

      END PROGRAM testCASP_WSP

      SUBROUTINE TestInitialization()
      INTEGER WSL, BP
      COMMON /CASP_WSP/WSL, BP

      IF (WSL == -1 .AND. BP == -1) THEN
         PRINT *, 'Test Passed: WSL and BP are correctly initialized.'
      ELSE
         PRINT *, 'Test Failed: WSL or BP are not correctly initialized.'
      END IF

      END SUBROUTINE TestInitialization