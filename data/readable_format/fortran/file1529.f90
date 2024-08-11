program testDb
    implicit none
    real :: xTest, result

    ! Test case 1
    xTest = 1.0e-11
    result = db(xTest)
    print *, "Test 1: x = ", xTest, "Expected: -99.0, Got: ", result

    ! Test case 2
    xTest = 1.259e-10
    result = db(xTest)
    print *, "Test 2: x = ", xTest, "Expected: -99.0, Got: ", result

    ! Test case 3
    xTest = 2.0e-10
    result = db(xTest)
    print *, "Test 3: x = ", xTest, "Expected: ", 10.0*log10(xTest), "Got: ", result

contains

    real function db(x)
        real, intent(in) :: x
        db = -99.0
        if (x > 1.259e-10) then
            db = 10.0 * log10(x)
        endif
    end function db

end program testDb