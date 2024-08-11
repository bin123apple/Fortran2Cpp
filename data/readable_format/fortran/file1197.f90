program test_getindx
    implicit none
    
    ! Declare variables for testing
    integer :: n, index
    real*8 :: min, siz, loc
    logical :: inflag

    ! Define test cases
    ! Test Case 1: loc is within range, should set inflag to TRUE
    n = 10
    min = 0.0
    siz = 1.0
    loc = 5.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 1: ", index, inflag

    ! Test Case 2: loc is below range, should adjust index to 1 and set inflag to FALSE
    loc = -1.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 2: ", index, inflag

    ! Test Case 3: loc is above range, should adjust index to n and set inflag to FALSE
    loc = 11.0
    call getindx(n, min, siz, loc, index, inflag)
    print *, "Test 3: ", index, inflag

    ! Add more test cases as needed
contains

    ! Define the getindx subroutine within the same file
    subroutine getindx(n, min, siz, loc, index, inflag)
        implicit none
        integer, intent(in) :: n
        real*8, intent(in) ::  min, siz, loc
        integer, intent(out) :: index 
        logical, intent(out) :: inflag

        index = int( (loc - min) / siz + 1.5 )

        if (index < 1) then
            index  = 1
            inflag = .FALSE. 
        else if (index > n) then
            index  = n
            inflag = .FALSE. 
        else
            inflag = .TRUE. 
        end if
    end subroutine getindx

end program test_getindx