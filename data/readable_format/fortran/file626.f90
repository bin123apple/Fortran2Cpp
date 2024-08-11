PROGRAM TestCommonBlock
      INTEGER*2 FTAR,TARHIB,TARBUF(10)
      COMMON /TARS/ FTAR, TARHIB, TARBUF

      CALL SetValues()
      CALL PrintValues()

      END

      SUBROUTINE SetValues()
      INTEGER*2 FTAR,TARHIB,TARBUF(10)
      COMMON /TARS/ FTAR, TARHIB, TARBUF

      FTAR = 1
      TARHIB = 2
      TARBUF(1) = 10
      TARBUF(2) = 20

      RETURN
      END

      SUBROUTINE PrintValues()
      INTEGER*2 FTAR,TARHIB,TARBUF(10)
      COMMON /TARS/ FTAR, TARHIB, TARBUF
      INTEGER I

      PRINT *, 'FTAR = ', FTAR
      PRINT *, 'TARHIB = ', TARHIB
      DO I = 1, 2
         PRINT *, 'TARBUF(', I, ') = ', TARBUF(I)
      END DO

      RETURN
      END