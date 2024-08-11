PROGRAM testGRTRML
      CHARACTER*3 CTERM
      INTEGER LTERM

      CALL GRTRML(CTERM, LTERM)

      IF (CTERM .EQ. 'CON' .AND. LTERM .EQ. 3) THEN
         PRINT *, 'Test passed'
      ELSE
         PRINT *, 'Test failed'
      END IF

      END

      SUBROUTINE GRTRML(CTERM, LTERM)
      CHARACTER*(*) CTERM
      INTEGER LTERM

      CTERM = 'CON'
      LTERM = 3
      RETURN
      END