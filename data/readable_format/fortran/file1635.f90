module m2345678901234567890123456789012345678901234567890123456789_123
contains
    subroutine setValue(arr, index, value)
        integer, intent(inout) :: arr(*)
        integer, intent(in) :: index
        integer, intent(in) :: value
        arr(index) = value
    end subroutine setValue
end module m2345678901234567890123456789012345678901234567890123456789_123

program test
    use m2345678901234567890123456789012345678901234567890123456789_123
    implicit none
    integer :: testArray(10)
    integer :: i

    ! Initialize array with zeros
    do i = 1, 10
        testArray(i) = 0
    end do

    ! Set the 5th element to 123
    call setValue(testArray, 5, 123)

    ! Check if the value was set correctly
    if (testArray(5) == 123) then
        print *, "Test passed."
    else
        print *, "Test failed."
    endif
end program test