! Define a module that contains the zstatn subroutine
module zstatn_module
  implicit none
contains
  ! The zstatn subroutine
  subroutine zstatn()
    ! Variables
    integer :: nopx, nbx, nrorth, nitref, nrstrt
    double precision :: tcaupd, tcaup2, tcaitr, tceigh, tcgets
    double precision :: tcapps, tcconv, titref, tgetv0, trvec
    double precision :: tmvopx, tmvbx

    ! Initialize variables
    nopx   = 0
    nbx    = 0
    nrorth = 0
    nitref = 0
    nrstrt = 0

    tcaupd = 0.0D+0
    tcaup2 = 0.0D+0
    tcaitr = 0.0D+0
    tceigh = 0.0D+0
    tcgets = 0.0D+0
    tcapps = 0.0D+0
    tcconv = 0.0D+0
    titref = 0.0D+0
    tgetv0 = 0.0D+0
    trvec  = 0.0D+0

    tmvopx = 0.0D+0
    tmvbx  = 0.0D+0

    print *, "zstatn subroutine called."
    ! Normally, you would do something with these variables, such as returning them or modifying passed-in parameters
  end subroutine zstatn
end module zstatn_module

! Main program to test the zstatn subroutine
program test_zstatn
  use zstatn_module
  implicit none

  ! Call the zstatn subroutine
  call zstatn()

  ! Test verification could go here
  ! Since zstatn doesn't currently modify any external variables or have output, this is a placeholder
  print *, "Test complete."

end program test_zstatn