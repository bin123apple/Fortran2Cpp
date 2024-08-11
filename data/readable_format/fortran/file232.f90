program testSaveTSG
    logical, parameter :: saveTSG = .TRUE.

    if (saveTSG .eqv. .TRUE.) then
        print *, "Test passed: saveTSG is TRUE."
    else
        print *, "Test failed: saveTSG is not TRUE."
    end if
end program testSaveTSG