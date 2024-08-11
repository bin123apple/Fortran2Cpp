module mod_class_fitness_calculator_exit_code
    implicit none
    
    type :: class_fitness_calculator_exit_code
        integer :: SUCCESS
        integer :: FAIL_AND_GIVE_UP
        integer :: FAIL_AND_TRY_AGAIN
    end type class_fitness_calculator_exit_code
end module mod_class_fitness_calculator_exit_code

program test_fitness_calculator_exit_code
    use mod_class_fitness_calculator_exit_code
    implicit none

    type(class_fitness_calculator_exit_code) :: fitness_calculator_exit_code

    ! Initialize the constants
    fitness_calculator_exit_code%SUCCESS = 0
    fitness_calculator_exit_code%FAIL_AND_GIVE_UP = 1
    fitness_calculator_exit_code%FAIL_AND_TRY_AGAIN = 2

    ! Test SUCCESS
    if (fitness_calculator_exit_code%SUCCESS == 0) then
        write(*,*) "SUCCESS test passed."
    else
        write(*,*) "SUCCESS test failed."
    endif

    ! Test FAIL_AND_GIVE_UP
    if (fitness_calculator_exit_code%FAIL_AND_GIVE_UP == 1) then
        write(*,*) "FAIL_AND_GIVE_UP test passed."
    else
        write(*,*) "FAIL_AND_GIVE_UP test failed."
    endif

    ! Test FAIL_AND_TRY_AGAIN
    if (fitness_calculator_exit_code%FAIL_AND_TRY_AGAIN == 2) then
        write(*,*) "FAIL_AND_TRY_AGAIN test passed."
    else
        write(*,*) "FAIL_AND_TRY_AGAIN test failed."
    endif
end program test_fitness_calculator_exit_code