! Define a program that uses the add function
program TestAddition
    implicit none
    integer :: sum

    ! Call the add function and store the result in sum
    sum = add(2, 3)

    ! Print the result
    print *, 'The sum of 2 and 3 is ', sum

contains

    ! This function adds two numbers
    function add(a, b)
        ! Declare the types of the variables
        integer, intent(in) :: a
        integer, intent(in) :: b
        integer :: add
        
        add = a + b
    end function add

end program TestAddition