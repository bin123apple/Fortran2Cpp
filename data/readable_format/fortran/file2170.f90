module m1
    integer :: i
end module m1

program main
    use m1
    implicit none

    ! Test the variable i
    call test_variable_i()
    
contains

    subroutine test_variable_i()
        use m1
        implicit none
        
        ! Assign a value to i
        i = 10
        
        ! Check if the value is correctly assigned
        if (i /= 10) then
            print *, 'Test failed: i is not equal to 10'
        else
            print *, 'Test passed: i is equal to 10'
        endif
    end subroutine test_variable_i

end program main