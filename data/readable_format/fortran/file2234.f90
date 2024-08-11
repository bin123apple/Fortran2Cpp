Program test_m5
  Implicit None
  
  Interface
    Function f()
      Real :: f
    End Function
    Function g()
      Real :: g
    End Function
  End Interface
  
  Call test_f()
  Call test_g()
  Call test_s()
  Print *, "All Fortran tests passed."
Contains
  Subroutine test_f()
    Real :: result
    result = f()
    Call assert(result == 1.0, "test_f failed")
  End Subroutine

  Subroutine test_g()
    Real :: result
    result = g()
    Call assert(result == 2.0, "test_g failed")
  End Subroutine

  Subroutine test_s()
    ! Since s() prints values, we will visually inspect the output
    Call s()
    Print *, "test_s visually inspected. No automatic check."
  End Subroutine

  Subroutine assert(condition, message)
    Logical, Intent(In) :: condition
    Character(*), Intent(In) :: message
    If (.Not. condition) Then
      Print *, message
      Stop 1
    End If
  End Subroutine

  Subroutine s
    Real :: p
    Interface
      Function f()
        Real :: f
      End Function
      Function g()
        Real :: g
      End Function
    End Interface
    Print *, g()
    p = f()
    Print *, p
    p = g()
    Print *, p
  End Subroutine

End Program

Real Function f()
  f = 1.0
End Function

Real Function g()
  g = 2.0
End Function