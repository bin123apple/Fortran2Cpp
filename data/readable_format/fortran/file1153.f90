Program TestFirstNonChar
    Implicit None
    Character*1 :: TestChar
    Character*20 :: TestString
    Integer :: Result

    Interface
        Function FirstNonChar(String, Char) Result(Position)
            Implicit None
            Character(*), Intent(In) :: String
            Character, Intent(In) :: Char
            Integer :: Position
        End Function FirstNonChar
    End Interface

    TestString = "aabacadae"
    TestChar = "a"
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 1 - Expected: 3, Got:", Result
    
    TestString = "aaaaaa"
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 2 - Expected: 0, Got:", Result
    
    TestString = ""
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 3 - Expected: 0, Got:", Result
    
    TestString = "bbbbbb"
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 4 - Expected: 1, Got:", Result
    
    TestString = "a"
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 5 - Expected: 0, Got:", Result
    
    TestString = "b"
    Result = FirstNonChar(TestString, TestChar)
    Print *, "Test 6 - Expected: 1, Got:", Result
End Program TestFirstNonChar

Function FirstNonChar(String, Char) Result(Position)
    Implicit None
    Character(*), Intent(In) :: String
    Character, Intent(In) :: Char
    Integer :: Position, i, LenString
    
    LenString = Len(Trim(String))
    Do i = 1, LenString
        If (String(i:i) /= Char) Then
            Position = i
            Return
        End If
    End Do
    Position = 0
End Function FirstNonChar