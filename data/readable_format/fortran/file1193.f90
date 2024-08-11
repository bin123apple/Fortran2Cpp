program futility_demo
    implicit none

    ! Variables for demonstration
    real :: arr(3) = [1.0, 2.0, 3.0]
    real :: dot_product_result
    real :: root
    real :: derivative_result
    real, parameter :: pi = 3.141592653589793

    ! Array I/O demonstration
    print *, "Array I/O demo:"
    call print_array(arr)

    ! Linear algebra demonstration (dot product)
    dot_product_result = dot_product(arr, arr)
    print *, "Dot product of arr with itself:", dot_product_result

    ! Root finding demonstration (placeholder function)
    root = find_root()
    print *, "Root found (placeholder):", root

    ! Calculus demonstration (derivative placeholder)
    derivative_result = calculate_derivative()
    print *, "Derivative result (placeholder):", derivative_result

    ! Physical values demonstration
    print *, "Value of PI:", pi

contains

    subroutine print_array(arr)
        real, dimension(:), intent(in) :: arr
        integer :: i
        do i = 1, size(arr)
            print *, "Element", i, ":", arr(i)
        end do
    end subroutine print_array

    function dot_product(a, b) result(product)
        real, dimension(:), intent(in) :: a, b
        real :: product
        product = sum(a*b)
    end function dot_product

    function find_root() result(root)
        ! Placeholder function for demonstration
        real :: root
        root = -1.0  ! Placeholder value
    end function find_root

    function calculate_derivative() result(derivative)
        ! Placeholder function for demonstration
        real :: derivative
        derivative = 0.0  ! Placeholder value
    end function calculate_derivative

end program futility_demo