subroutine numtext(value, str)
    character(len=12) :: str
    real :: value, test
    test = abs(value)
    write(str, '(F12.0)') value
    if (test <= 999999.0) write(str, '(F12.2)') value
    if (test <= 999.0) write(str, '(F12.3)') value
    if (test <= 0.9) write(str, '(F12.4)') value
    if (test <= 0.09) write(str, '(F12.5)') value
    if (test <= 0.009) write(str, '(F12.6)') value
    if (test <= 0.0009) write(str, '(F12.7)') value
    if (test <= 0.00009) write(str, '(F12.8)') value
    if (test <= 0.000009) write(str, '(F12.9)') value
    if (test == 0.0) write(str, '(F12.1)') value
end subroutine numtext

program test
    character(len=12) :: str

    call numtext(1234567.0, str)
    print *, str
end program test