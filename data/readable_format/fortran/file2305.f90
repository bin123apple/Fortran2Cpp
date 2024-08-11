program test_fortran
    implicit none
    character(len=20) :: output
    character(len=20) :: expected_output

    ! Redirect output to a file
    open(unit=10, file='output.txt', status='replace')
    write(10, '(A)') "Hello world"
    close(10)

    ! Read the output
    open(unit=10, file='output.txt', status='old')
    read(10, '(A)') output
    close(10)

    ! Expected output
    expected_output = "Hello world"

    ! Compare output
    if (trim(output) == expected_output) then
        print *, "Test passed"
    else
        print *, "Test failed"
    end if
end program test_fortran