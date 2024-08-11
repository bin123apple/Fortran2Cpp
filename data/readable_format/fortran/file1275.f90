! single_file_example.f90
program single_file_example
    implicit none

    ! Define precision
    integer, parameter :: wp = selected_real_kind(15, 307)

    ! Define the 'dis' type within the program
    type :: dis
        real(wp) :: x, y, z
        real(wp) :: mag, mag2
        real(wp) :: riy, rjy, yim
        real(wp) :: magim, mag2im
        real(wp) :: rjx, rjz
        real(wp) :: rix, riz
    end type dis

    ! Variable declaration
    type(dis) :: test_var

    ! Main program block
    ! Initialize variables or perform operations
    test_var%x = 1.0_wp
    test_var%y = 2.0_wp
    test_var%z = 3.0_wp

    ! Display the values to ensure everything is working
    print *, "x = ", test_var%x
    print *, "y = ", test_var%y
    print *, "z = ", test_var%z

end program single_file_example