module mod_arrays

    implicit none

    private
    public :: reverse
    public :: average
    public :: std
    public :: moving_average
    public :: moving_std

contains

    pure function reverse(x)
        real, intent(in) :: x(:)
        real :: reverse(size(x))

        reverse = x(size(x):1:-1)
    end function reverse

    pure real function average(x)
        real, intent(in) :: x(:)

        average = sum(x) / size(x)
    end function average

    pure real function std(x)
        real, intent(in) :: x(:)

        std = sqrt(average((x - average(x))**2))
    end function std

    pure function moving_average(x, window_size) result(ma)
        real, intent(in) :: x(:)
        integer, intent(in) :: window_size
        real :: ma(size(x))
        integer :: i, lower_bound

        do i = 1, size(x)
            lower_bound = max(i - window_size + 1, 1)
            ma(i) = average(x(lower_bound:i))
        end do
    end function moving_average

    pure function moving_std(x, window_size) result(ms)
        real, intent(in) :: x(:)
        integer, intent(in) :: window_size
        real :: ms(size(x))
        integer :: i, lower_bound

        do i = 1, size(x)
            lower_bound = max(i - window_size + 1, 1)
            ms(i) = std(x(lower_bound:i))
        end do
    end function moving_std

end module mod_arrays

program test_mod_arrays
    use mod_arrays
    implicit none
    real, allocatable :: testArray(:)
    real :: result
    integer :: i

    ! Test with a simple array
    allocate(testArray(5))
    testArray = [1.0, 2.0, 3.0, 4.0, 5.0]

    ! Test reverse
    print *, "Original Array: ", testArray
    print *, "Reversed Array: ", reverse(testArray)

    ! Test average
    result = average(testArray)
    print *, "Average: ", result

    ! Test standard deviation
    result = std(testArray)
    print *, "Standard Deviation: ", result

    ! Test moving average
    print *, "Moving Average (window_size=3): ", moving_average(testArray, 3)

    ! Test moving standard deviation
    print *, "Moving Standard Deviation (window_size=3): ", moving_std(testArray, 3)

    deallocate(testArray)
end program test_mod_arrays