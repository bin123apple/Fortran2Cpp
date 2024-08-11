module mo_column
    contains
        subroutine compute(nz, q, t, nproma)
            integer, intent(in) :: nproma
            integer, intent(in) :: nz
            real, intent(inout) :: t(nz, nproma)
            real, intent(inout) :: q(nz, nproma)
            
            call compute_column(nz, q, t, nproma)
        end subroutine compute
        
        subroutine compute_column(nz, q, t, nproma)
            integer, intent(in) :: nproma
            integer, intent(in) :: nz
            real, intent(inout) :: t(nz, nproma)
            real, intent(inout) :: q(nz, nproma)
            integer :: k, proma
            real :: c
            
            c = 5.345
            do k = 2, nz
                do proma = 1, nproma
                    t(k, proma) = c * k
                    q(k, proma) = q(k - 1, proma) + t(k, proma) * c
                end do
            end do
            do proma = 1, nproma
                q(nz, proma) = q(nz, proma) * c
            end do
        end subroutine compute_column
end module mo_column

program testMoColumn
    use mo_column
    implicit none

    integer, parameter :: nz = 5, nproma = 3
    real :: q(nz, nproma), t(nz, nproma)
    integer :: i, j

    ! Initialize arrays
    q = 0.0
    t = 0.0

    call compute(nz, q, t, nproma)

    ! Print results for manual verification
    print *, "t array:"
    do i = 1, nz
        write(*, "(5F10.2)"), t(i, :)
    end do

    print *, "q array:"
    do i = 1, nz
        write(*, "(5F10.2)"), q(i, :)
    end do
end program testMoColumn