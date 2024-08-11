! r3dot_module.f90
Module R3dotModule
    Implicit None
Contains
    Real (8) Function r3dot (x, y)
        Implicit None
        Real (8), Intent (In) :: x(3)
        Real (8), Intent (In) :: y(3)
        r3dot = x(1) * y(1) + x(2) * y(2) + x(3) * y(3)
    End Function r3dot
End Module R3dotModule

! test_r3dot.f90
Program TestR3dot
    Use R3dotModule
    Implicit None
    Real(8) :: x(3), y(3), result

    ! Test 1
    x = (/1.0d0, 2.0d0, 3.0d0/)
    y = (/4.0d0, 5.0d0, 6.0d0/)
    result = r3dot(x, y)
    Print *, "Test 1 Result: ", result  ! Expected: 32.0

    ! Add more tests as needed
End Program TestR3dot