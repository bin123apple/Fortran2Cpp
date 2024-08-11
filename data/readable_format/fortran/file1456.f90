program test_dh_board
    implicit none
    double precision :: dh_board
    external :: dh_board

    ! Declare the variables in the common block
    double precision fcr1, fcr2, dfcr1, dfcr2
    double precision tcr1, tcr2, dtcr1, dtcr2, ampcr
    common /brd_dh/ fcr1, fcr2, dfcr1, dfcr2, tcr1, tcr2, dtcr1, dtcr2, ampcr

    ! Initialize variables
    fcr1 = 1.0
    fcr2 = 5.0
    dfcr1 = 0.5
    dfcr2 = 0.5
    tcr1 = 1.0
    tcr2 = 5.0
    dtcr1 = 0.5
    dtcr2 = 0.5
    ampcr = 10.0

    ! Test cases
    print *, 'dh_board(2.0, 2.0) = ', dh_board(2.0, 2.0)
    print *, 'dh_board(6.0, 2.0) = ', dh_board(6.0, 2.0)
    print *, 'dh_board(2.0, 6.0) = ', dh_board(2.0, 6.0)
    print *, 'dh_board(3.5, 3.5) = ', dh_board(3.5, 3.5)

end program test_dh_board

! Function definition
double precision function dh_board(fi, tet)
    implicit none
    double precision, intent(in) :: fi, tet
    ! Declare the variables in the common block
    double precision fcr1, fcr2, dfcr1, dfcr2
    double precision tcr1, tcr2, dtcr1, dtcr2, ampcr
    common /brd_dh/ fcr1, fcr2, dfcr1, dfcr2, tcr1, tcr2, dtcr1, dtcr2, ampcr

    ! Function implementation (simplified for demonstration)
    dh_board = 0.0
    ! Add your original dh_board logic here

end function dh_board