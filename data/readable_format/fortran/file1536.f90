module control_bunch_input
    implicit none
    integer :: input_parameter = 10
    real(8) :: input_value = 25.5

contains

    subroutine set_input_parameter(value)
        integer, intent(in) :: value
        input_parameter = value
    end subroutine set_input_parameter

    function get_input_value() result(value)
        real(8) :: value
        value = input_value
    end function get_input_value

end module control_bunch_input

program test_control_bunch_input
    use control_bunch_input
    implicit none

    ! Test setting the input parameter
    call set_input_parameter(20)
    if (input_parameter /= 20) then
        print *, 'Test failed: input_parameter did not update correctly.'
    else
        print *, 'Test passed: input_parameter updated correctly.'
    endif

    ! Test getting the input value
    if (get_input_value() == 25.5) then
        print *, 'Test passed: get_input_value() returned the correct value.'
    else
        print *, 'Test failed: get_input_value() did not return the correct value.'
    endif

end program test_control_bunch_input