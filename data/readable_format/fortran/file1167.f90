subroutine applympc(vfa, n)
    implicit none
    integer, intent(in) :: n
    real(8), intent(inout) :: vfa(0:n-1)
    integer :: i

    do i = 0, n-1
        if (mod(i, 2) == 0) then
            vfa(i) = vfa(i) + 1.0
        else
            vfa(i) = vfa(i) - 1.0
        endif
    enddo
end subroutine applympc

program test
    integer, parameter :: n = 4
    real(8) :: vfa(0:n-1)
    integer :: i

    ! Initialize vfa
    do i = 0, n-1
        vfa(i) = i*1.0
    enddo

    call applympc(vfa, n)

    ! Print results for verification
    do i = 0, n-1
        print *, "vfa(", i, ") = ", vfa(i)
    enddo
end program test