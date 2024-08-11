program conversion_tipos_tests
    implicit none
    integer :: int = 6
    real :: r_var = 3.5
    complex :: z = (2, 5.9)
    complex :: expected_complex
    real :: expected_real

    ! Test Complex + Integer
    expected_complex = (8, 5.9)
    if (z + int == expected_complex) then
        print *, "Test Complex + Integer Passed"
    else
        print *, "Test Complex + Integer Failed"
    end if

    ! Test Complex + Real
    expected_complex = (5.5, 5.9)
    if (r_var + z == expected_complex) then
        print *, "Test Complex + Real Passed"
    else
        print *, "Test Complex + Real Failed"
    end if

    ! Test Real + Integer
    expected_real = 9.5
    if (r_var + int == expected_real) then
        print *, "Test Real + Integer Passed"
    else
        print *, "Test Real + Integer Failed"
    end if

end program conversion_tipos_tests