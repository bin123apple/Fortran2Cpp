module sum_module
    implicit none
contains
    function sumSelectedIntegers(array, size, mask) result(sum)
        integer(kind=2), intent(in) :: array(*)
        integer(kind=4), intent(in) :: size
        logical, intent(in) :: mask(*)
        integer(kind=2) :: sum
        integer :: i

        sum = 0
        do i = 1, size
            if (mask(i)) then
                sum = sum + array(i)
            end if
        end do
    end function sumSelectedIntegers
end module sum_module

program test
    use sum_module
    implicit none

    integer(kind=2) :: array(5) = [1, 2, 3, 4, 5]
    logical :: mask(5) = [.true., .false., .true., .false., .true.]
    integer(kind=2) :: result
    integer(kind=2) :: expected = 9
    integer(kind=4) :: size = 5

    result = sumSelectedIntegers(array, size, mask)

    if (result == expected) then
        print *, "Test passed."
    else
        print *, "Test failed: Expected", expected, "got", result, "."
    end if
end program test