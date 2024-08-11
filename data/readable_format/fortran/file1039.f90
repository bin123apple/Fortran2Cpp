module rrsw_kg16
    implicit none
    real(kind=8), parameter :: constant1 = 1.0

contains

    subroutine printConstant()
        print *, "Constant1 is ", constant1
    end subroutine printConstant

    function square(x) result(res)
        real(kind=8), intent(in) :: x
        real(kind=8) :: res
        res = x**2
    end function square

end module rrsw_kg16

program test_rrsw_kg16
    use rrsw_kg16
    implicit none
    real(kind=8) :: value, result

    call printConstant()

    value = 2.0
    result = square(value)
    print *, "Square of ", value, " is ", result

end program test_rrsw_kg16