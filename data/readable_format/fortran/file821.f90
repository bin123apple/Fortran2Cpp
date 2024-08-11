module UnitValue_Module
    implicit none
    private
    public :: UnitValue, add_values

    type :: UnitValue
        real :: value
        character(len=2) :: unit
    end type UnitValue

contains

    function add_values(a, b) result(c)
        type(UnitValue), intent(in) :: a, b
        type(UnitValue) :: c

        ! Assuming both values are in the same unit for simplicity
        c%value = a%value + b%value
        c%unit = a%unit
    end function add_values

end module UnitValue_Module

program TestProgram
    use UnitValue_Module
    implicit none

    type(UnitValue) :: uv1, uv2, result

    ! Initialize unit values
    uv1%value = 10.0
    uv1%unit = 'kg'
    uv2%value = 20.0
    uv2%unit = 'kg'

    ! Test adding two UnitValues
    result = add_values(uv1, uv2)

    print *, "Result: ", result%value, result%unit
end program TestProgram