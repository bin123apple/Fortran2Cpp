Program TestJuldy
  Implicit None
  Integer*4 :: Result

  ! Test 1: Non-leap year February 28
  Result = Juldy(2, 28, 2021)
  If (Result .ne. 59) Then
    Print *, "Test 1 failed."
  Else
    Print *, "Test 1 passed."
  End If

  ! Test 2: Leap year February 29
  Result = Juldy(2, 29, 2020)
  If (Result .ne. 60) Then
    Print *, "Test 2 failed."
  Else
    Print *, "Test 2 passed."
  End If

  ! Test 3: Invalid month
  Result = Juldy(13, 10, 2020)
  If (Result .ne. -999) Then
    Print *, "Test 3 failed."
  Else
    Print *, "Test 3 passed."
  End If

  ! Test 4: Early year (before 1800)
  Result = Juldy(3, 15, 1700)
  If (Result .ne. -999) Then
    Print *, "Test 4 failed."
  Else
    Print *, "Test 4 passed."
  End If

  ! Test 5: End of year
  Result = Juldy(12, 31, 2020)
  If (Result .ne. 366) Then
    Print *, "Test 5 failed."
  Else
    Print *, "Test 5 passed."
  End If

Contains

  Integer*4 Function Juldy(Imon,Id,Iy)
    Implicit None
    Integer*4 Iy,Imon,Id
    Integer*4 ITD(12)
    Data ITD /31,59,90,120,151,181,212,243,273,304,334,365/

    If ((Iy.Lt.1800) .Or. (Imon.Lt.1) .Or. (Imon.Gt.12)) Then
      Juldy = -999
      Return
    End If
    Juldy = Id
    If (Imon.Eq.1) Return
    Juldy = Juldy + ITD(Imon-1)
    If ((Imon.Ge.3) .And. (Mod(Iy,4).Eq.0) .And. ((Mod(Iy,400).Eq.0) .Or. (Mod(Iy,100).Ne.0))) Then
      Juldy = Juldy + 1
    End If
    Return
  End Function Juldy

End Program TestJuldy