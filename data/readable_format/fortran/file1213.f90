module arrayOps
    implicit none
contains
    subroutine filltab(dimx, dimy, ftab)
        integer, intent(in) :: dimx, dimy
        real, intent(out) :: ftab(dimx, dimy)
        integer :: x, y

        do x = 1, dimx
            do y = 1, dimy
                ftab(x, y) = x * 100 + y
            end do
        end do
    end subroutine filltab

    subroutine printtab(tab, dimx, dimy)
        integer, intent(in) :: dimx, dimy
        real, intent(in) :: tab(dimx, dimy)
        integer :: x, y

        do x = 1, dimx
            ! Adjusted format string to remove comma before I/O list
            write(*, '(I3, 2X, 6F8.1)') x, (tab(x, y), y = 1, dimy)
        end do
    end subroutine printtab
end module arrayOps

program test
    use arrayOps
    implicit none

    ! Declarations
    integer :: dimx = 8, dimy = 6
    real, allocatable :: ftab(:,:)

    ! Allocate the array
    allocate(ftab(dimx, dimy))

    ! Procedure calls
    call filltab(dimx, dimy, ftab)
    call printtab(ftab, dimx, dimy)

    ! Deallocate the array
    deallocate(ftab)
end program test