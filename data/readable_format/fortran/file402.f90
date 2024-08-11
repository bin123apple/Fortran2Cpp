! Define a module that contains the procedures.
module ppm_module_tree_boxcut
    implicit none
    contains
    ! Single precision function
    function ppm_tree_boxcut_s(x) result(res)
        real(kind=4), intent(in) :: x
        real(kind=4) :: res
        res = x * x
    end function ppm_tree_boxcut_s

    ! Double precision function
    function ppm_tree_boxcut_d(x) result(res)
        real(kind=8), intent(in) :: x
        real(kind=8) :: res
        res = x * x
    end function ppm_tree_boxcut_d
end module ppm_module_tree_boxcut

! Test program
program test_ppm_tree_boxcut
    use ppm_module_tree_boxcut
    implicit none

    real(kind=4) :: single_precision_input = 2.0_4
    real(kind=8) :: double_precision_input = 2.0_8
    real(kind=4) :: single_precision_result
    real(kind=8) :: double_precision_result

    ! Test the single precision function
    single_precision_result = ppm_tree_boxcut_s(single_precision_input)
    print *, "Single Precision Result: ", single_precision_result

    ! Test the double precision function
    double_precision_result = ppm_tree_boxcut_d(double_precision_input)
    print *, "Double Precision Result: ", double_precision_result

    ! Assertions or checks can be implemented here as needed
end program test_ppm_tree_boxcut