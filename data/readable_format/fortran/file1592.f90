Program TestLastNonChar
    Implicit none
    Integer :: Result
    Character(len=20) :: testString
    Character(len=1) :: testChar

    ! Test 1: Specified character is at the end of the string
    testString = 'hello world!'
    testChar = '!'
    Result = LastNonChar(testString, testChar)
    print *, 'Test 1:', Result

    ! Test 2: Specified character is not in the string
    testString = 'hello world'
    testChar = 'x'
    Result = LastNonChar(testString, testChar)
    print *, 'Test 2:', Result

    ! Test 3: String contains only the specified character
    testString = 'aaaaa'
    testChar = 'a'
    Result = LastNonChar(testString, testChar)
    print *, 'Test 3:', Result

    ! Test 4: String is empty
    testString = ''
    testChar = 'z'
    Result = LastNonChar(testString, testChar)
    print *, 'Test 4:', Result

Contains
    Integer Function LastNonChar(String, Char)
        Implicit none
        Character(len=*), Intent(In) :: String
        Character(len=1), Intent(In) :: Char
        Integer :: i

        LastNonChar = Len(Trim(String))
        Do i = LastNonChar, 1, -1
            If (String(i:i) .ne. Char) Then
                LastNonChar = i
                Return
            End If
        End Do
        LastNonChar = 0
    End Function LastNonChar

End Program TestLastNonChar