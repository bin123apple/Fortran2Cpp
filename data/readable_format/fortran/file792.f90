program testProgram
    use, intrinsic :: iso_fortran_env, only: int32
    implicit none
    integer(int32) :: test_status

    interface
        function run_tests() result(status)
            import :: int32
            integer(int32) :: status
        end function run_tests
    end interface

    ! Call the run_tests function
    test_status = run_tests()
    if (test_status == 0) then
        print *, "Test Passed"
    else
        print *, "Test Failed with status: ", test_status
    endif
end program testProgram

function run_tests() result(status)
    use, intrinsic :: iso_fortran_env, only: int32
    implicit none
    integer(int32) :: status
    integer :: i
    integer, parameter :: m(4,4) = reshape([ (i, i=1, 16) ], [4, 4])
    integer, parameter :: sevens = count(m == 7)
    integer, parameter :: odd(4) = count(mod(m, 2) == 1, dim=1)
    integer, parameter :: even = count(mod(m, 2) == 0)

    ! Initialize status to a default value indicating success
    status = 0

    ! Perform the checks as per the original logic
    if (sevens /= 1) then
        status = 1
    else if (any(odd /= [2,2,2,2])) then
        status = 2
    else if (even /= 8) then
        status = 3
    endif
end function run_tests