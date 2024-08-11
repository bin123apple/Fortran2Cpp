Program TestStheta_sq
    Implicit None
    Real(8) :: x, result

    ! Test case 1: x < -0.5
    x = -0.75
    result = stheta_sq(x)
    Print *, "stheta_sq(", x, ") = ", result

    ! Test case 2: -0.5 <= x < 0.5
    x = 0.25
    result = stheta_sq(x)
    Print *, "stheta_sq(", x, ") = ", result

    ! Test case 3: x >= 0.5
    x = 0.75
    result = stheta_sq(x)
    Print *, "stheta_sq(", x, ") = ", result
    
Contains

    Real(8) Function stheta_sq(x)
        Implicit None
        Real(8), Intent(In) :: x

        If (x .Le. -0.5d0) Then
            stheta_sq = 0.d0
            Return
        End If
        If (x .Lt. 0.5d0) Then
            stheta_sq = x + 0.5d0
        Else
            stheta_sq = 1.d0
        End If
    End Function stheta_sq

End Program TestStheta_sq