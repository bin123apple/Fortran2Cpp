program t
    implicit none
    integer :: a = 1
    integer :: b = 2
    double precision :: j = 3.14
    double precision :: expected = 3.14
    double precision :: tolerance = 0.01

    ! Original program functionality
    write(*, '(F4.2)') j

    ! Simple test
    if (abs(j - expected) > tolerance) then
        print *, "Test Failed: Value does not match expected."
    else
        print *, "Test Passed."
    end if
end program t