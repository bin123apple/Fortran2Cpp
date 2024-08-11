module w3reddat_mod
contains
    subroutine w3reddat(itm)
        integer, parameter :: itd(5) = (/1,24,1440,86400,86400000/)
        integer, dimension(4), intent(out) :: itm
        integer :: i
        do i=1,4
            itm(i) = itd(5) / itd(i)
        end do
    end subroutine w3reddat
end module w3reddat_mod

program test
    use w3reddat_mod
    integer, dimension(4) :: itm
    call w3reddat(itm)
    print *, itm
end program test