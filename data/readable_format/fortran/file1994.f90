program testS
    implicit none

    integer, dimension(3) :: intArray = [1, 2, 3]
    real, dimension(2) :: realArray = [1.1, 2.2]
    integer :: singleInt = 5

    call s_intArray(intArray)
    call s_realArray(realArray)
    call s_singleInt(singleInt)

contains

    subroutine s_intArray(arg)
        integer, dimension(:), intent(in) :: arg
        print *, "s_intArray called with integers:", arg
    end subroutine s_intArray

    subroutine s_realArray(arg)
        real, dimension(:), intent(in) :: arg
        print *, "s_realArray called with reals:", arg
    end subroutine s_realArray

    subroutine s_singleInt(arg)
        integer, intent(in) :: arg
        print *, "s_singleInt called with single integer:", arg
    end subroutine s_singleInt

end program testS