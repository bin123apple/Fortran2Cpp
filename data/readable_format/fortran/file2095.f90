program testWritesta
    implicit none
    
    ! Variables
    integer :: istep, j, icutb, l
    real*8 :: ttime, time, dtime
    
    ! Assign test values
    istep = 1
    j = 2
    icutb = 3
    l = 4
    ttime = 5.0
    time = 6.0
    dtime = 0.5
    
    ! Call the subroutine
    call writesta(istep, j, icutb, l, ttime, time, dtime)

end program testWritesta

subroutine writesta(istep, j, icutb, l, ttime, time, dtime)
    implicit none

    integer istep, j, icutb, l
    real*8 ttime, time, dtime

    ! Printing to a specific unit (file) with format
    write(8,100) istep, j, icutb+1, l, ttime+time, time, dtime
    flush(8)

100 format(1x,i5,1x,i10,2(1x,i5),3(1x,e13.6))

end subroutine writesta