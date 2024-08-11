Program TestVP
    Implicit None
    Double Precision VP
    Double Precision, Dimension(3) :: T = [25.0, 50.0, 100.0]
    Integer :: i

    Do i = 1, 3
        Print *, 'VP(', T(i), ') = ', VP(T(i))
    End Do
End Program

Double Precision Function VP(T)
    Double Precision, Intent(In) :: T
    Double Precision :: TT
    TT = T + 273.16
    VP = 10.0d0**(22.5518d0 - (2937.4d0 / TT) - 4.9283d0 * DLOG10(TT)) * 10.0d0
    Return
End Function