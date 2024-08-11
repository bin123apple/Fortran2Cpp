Program Main
    Implicit None
    Character(len=100) :: scrpath = './test/'
    Character(len=5) :: filext = '.txt'

    ! Setting up testing environment
    Call SetupTestEnvironment(scrpath, filext)
    
    ! Running the delevec subroutine
    Call delevec(scrpath, filext)
    
    ! Testing file deletion
    Call TestFileDeletion(scrpath, filext)

Contains

    Subroutine delevec(scrpath, filext)
        Character(len=*), Intent(In) :: scrpath, filext
        Logical :: exist
        Character(len=100) :: filePath

        ! Check and delete EVECFV file
        filePath = Trim(scrpath)//'EVECFV'//Trim(filext)
        Inquire(File=filePath, Exist=exist)
        If (exist) Then
            Open(Unit=71, File=filePath, Status='Old')
            Close(Unit=71, Status='Delete')
        End If

        ! Check and delete EVECSV file
        filePath = Trim(scrpath)//'EVECSV'//Trim(filext)
        Inquire(File=filePath, Exist=exist)
        If (exist) Then
            Open(Unit=71, File=filePath, Status='Old')
            Close(Unit=71, Status='Delete')
        End If
    End Subroutine delevec

    Subroutine SetupTestEnvironment(scrpath, filext)
        Character(len=*), Intent(In) :: scrpath, filext
        Call Execute_Command_Line('mkdir -p '//Trim(scrpath))
        Call Execute_Command_Line('touch '//Trim(scrpath)//'EVECFV'//Trim(filext))
        Call Execute_Command_Line('touch '//Trim(scrpath)//'EVECSV'//Trim(filext))
    End Subroutine SetupTestEnvironment

    Subroutine TestFileDeletion(scrpath, filext)
        Character(len=*), Intent(In) :: scrpath, filext
        Logical :: exist

        ! Check EVECFV file deletion
        Inquire(File=Trim(scrpath)//'EVECFV'//Trim(filext), Exist=exist)
        If (.Not. exist) Then
            Print *, "Test Passed: EVECFV file deleted."
        Else
            Print *, "Test Failed: EVECFV file not deleted."
        End If

        ! Check EVECSV file deletion
        Inquire(File=Trim(scrpath)//'EVECSV'//Trim(filext), Exist=exist)
        If (.Not. exist) Then
            Print *, "Test Passed: EVECSV file deleted."
        Else
            Print *, "Test Failed: EVECSV file not deleted."
        End If
    End Subroutine TestFileDeletion

End Program Main