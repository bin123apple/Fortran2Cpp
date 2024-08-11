program testAddNumbers
    implicit none
    real :: result

    ! Test Case 1: Positive numbers
    result = addNumbers(5.0, 3.0)
    print *, "Test Case 1 (5.0 + 3.0): Expected 8.0, Got ", result

    ! Test Case 2: Negative numbers
    result = addNumbers(-2.0, -3.0)
    print *, "Test Case 2 (-2.0 + -3.0): Expected -5.0, Got ", result

    ! Test Case 3: Mixed numbers
    result = addNumbers(-5.0, 10.0)
    print *, "Test Case 3 (-5.0 + 10.0): Expected 5.0, Got ", result

contains
    ! The function to add two numbers
    function addNumbers(a, b) result(sum)
        real, intent(in) :: a, b
        real :: sum
        sum = a + b
    end function addNumbers
end program testAddNumbers