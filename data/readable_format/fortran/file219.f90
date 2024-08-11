program main
    implicit none

    ! Global variables
    real :: xmax, xmin

    ! Initialize global variables
    xmax = 10.0
    xmin = 5.0

    ! Check parameters
    call checa_parametros(xmax, xmin)

contains

    ! Subroutine to check parameters
    subroutine checa_parametros(xmax, xmin)
        implicit none
        real, intent(in) :: xmax, xmin

        if (xmax <= xmin) then
            print *, 'Error xmax<=xmin'
            stop
        end if
    end subroutine checa_parametros

end program main