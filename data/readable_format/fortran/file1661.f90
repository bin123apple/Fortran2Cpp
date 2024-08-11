! switch1.f90
subroutine switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
    implicit none
    real, intent(inout) :: sw, dsw
    real, intent(in) :: z, p1, ip1, zmemb1, zmemb2
    real :: delz, delzp1
    
    if (z >= (zmemb2 + p1) .or. z <= (zmemb1 - p1)) then
        sw = 0.0
        dsw = 0.0
    else
        if (z > zmemb2) then
            delz = z - zmemb2
            delzp1 = delz * ip1
            sw = 1.0 + (2.0 * delzp1 - 3.0) * delzp1**2
            dsw = -6.0 * (delzp1 - 1.0) * ip1 * delzp1
        elseif (z < zmemb1) then
            delz = zmemb1 - z
            delzp1 = delz * ip1
            sw = 1.0 + (2.0 * delzp1 - 3.0) * delzp1**2
            dsw = 6.0 * (delzp1 - 1.0) * ip1 * delzp1
        else
            sw = 1.0
            dsw = 0.0
        endif
    endif
end subroutine switch1

program testSwitch1
    implicit none
    real :: sw, dsw, z, p1, ip1, zmemb1, zmemb2

    ! Test case 1
    call test(1.5, 0.5, 2.0, 1.0, 2.0)

    ! Test case 2
    call test(0.5, 0.5, 2.0, 1.0, 2.0)

    ! Test case 3
    call test(2.5, 0.5, 2.0, 1.0, 2.0)

    ! Test case 4
    call test(1.5, 0.5, 2.0, 0.0, 3.0)

contains

    subroutine test(z, p1, ip1, zmemb1, zmemb2)
        real, intent(in) :: z, p1, ip1, zmemb1, zmemb2
        real :: sw, dsw
        call switch1(sw, dsw, z, p1, ip1, zmemb1, zmemb2)
        print *, 'z=', z, 'p1=', p1, 'ip1=', ip1, 'zmemb1=', zmemb1, 'zmemb2=', zmemb2, 'sw=', sw, 'dsw=', dsw
    end subroutine test

end program testSwitch1