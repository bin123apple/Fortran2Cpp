module gridQ_module
    implicit none
    ! Declare the variables
    integer :: nQ2g
    integer :: inter_degreeQ
    character(len=20) :: InQGrid
contains
    ! Include the subroutine within the module
    subroutine SetQGridParameters(npQ, degQ)
        implicit none
        integer, intent(in) :: npQ, degQ

        nQ2g = npQ
        inter_degreeQ = degQ
        InQGrid = "done"
    end subroutine SetQGridParameters
end module gridQ_module

program test_setqgrid
    use gridQ_module
    implicit none
    integer :: npQ, degQ
    integer :: errors

    ! Initialize variables
    errors = 0

    ! Test parameters
    npQ = 10
    degQ = 5

    ! Call the subroutine
    call SetQGridParameters(npQ, degQ)

    ! Check the variables
    if (nQ2g /= npQ) then
        print *, "Error: nQ2g is incorrect"
        errors = errors + 1
    endif

    if (inter_degreeQ /= degQ) then
        print *, "Error: inter_degreeQ is incorrect"
        errors = errors + 1
    endif

    if (InQGrid /= 'done') then
        print *, "Error: InQGrid is incorrect"
        errors = errors + 1
    endif

    ! Print the result
    if (errors == 0) then
        print *, "All tests passed."
    else
        print *, "Number of errors: ", errors
    endif

end program test_setqgrid