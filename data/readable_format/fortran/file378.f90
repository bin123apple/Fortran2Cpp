MODULE powsq_I
  INTERFACE
    SUBROUTINE powsq(n, result)
      INTEGER, INTENT(IN) :: n
      INTEGER, INTENT(OUT) :: result
    END SUBROUTINE  
  END INTERFACE 
END MODULE

SUBROUTINE powsq(n, result)
  INTEGER, INTENT(IN) :: n
  INTEGER, INTENT(OUT) :: result
  result = n**2
END SUBROUTINE  

PROGRAM test_powsq
  USE powsq_I
  INTEGER :: number, squared
  
  number = 4
  CALL powsq(number, squared)
  PRINT *, "Square of ", number, " is ", squared
END PROGRAM test_powsq