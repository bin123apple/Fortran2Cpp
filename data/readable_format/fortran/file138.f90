program test_c_arrays
    implicit none
    real, allocatable :: x(:), y(:), a(:), b(:)
    real :: result
    integer :: i

    ! Allocate and initialize test arrays
    allocate(x(5), y(3), a(3), b(3))
    x = [1.0, 2.0, 3.0, 4.0, 5.0]
    y = [1.0, 2.0, 3.0]
    a = [1.0, 2.0, 3.0]
    b = [4.0, 5.0, 6.0]

    ! Test 1: Summing all elements of an array
    result = array_in(x, size(x))
    print *, "Test 1 (Sum of all elements): ", result

    ! Test 2: Summing the first four elements of an array
    result = array_in_2(y)
    print *, "Test 2 (Sum of first four elements): ", result

    ! Test 3: Setting all elements of two arrays x and y to 20 and 30
    call array_out(x, y, size(x), size(y))
    print *, "Test 3 (x after setting to 20): ", x
    print *, "Test 3 (y after setting to 30): ", y

    ! Test 4: Calculating the dot product of two arrays
    result = inner_prod(a, b, size(a))
    print *, "Test 4 (Dot product of a and b): ", result

contains
    ! Function 1: Sum elements of an array
    function array_in(x, n) result(sum)
        real, intent(in) :: x(:)
        integer, intent(in) :: n
        real :: sum
        sum = 0.0
        do i = 1, n
            sum = sum + x(i)
        end do
    end function array_in

    ! Function 2: Sum the first four elements of an array
    function array_in_2(x) result(sum)
        real, intent(in) :: x(:)
        real :: sum
        integer :: i, upb
        upb = min(size(x), 4) ! Upper bound is the smaller of 4 or the array size
        sum = 0.0
        do i = 1, upb
            sum = sum + x(i)
        end do
    end function array_in_2

    ! Subroutine 3: Set all elements of x to 20 and all elements of y to 30
    subroutine array_out(x, y, nx, ny)
        integer, intent(in) :: nx, ny
        real, intent(inout) :: x(nx), y(ny)
        x(:) = 20.0
        y(:) = 30.0
    end subroutine array_out

    ! Function 4: Calculate the dot product of two arrays
    function inner_prod(a, b, n) result(dot_product)
        real, intent(in) :: a(:), b(:)
        integer, intent(in) :: n
        real :: dot_product
        integer :: i
        dot_product = 0.0
        do i = 1, n
            dot_product = dot_product + a(i) * b(i)
        end do
    end function inner_prod
end program test_c_arrays