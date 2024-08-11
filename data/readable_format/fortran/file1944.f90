program testFormat
    implicit none
    real :: num = 123.456

    write(*,10) num
    10 format (F10.3)

end program testFormat