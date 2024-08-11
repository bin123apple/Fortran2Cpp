module ycwu_module
    implicit none

    public :: rysfun

contains

    subroutine rysfun(ff)
        integer(kind=kind(1)) :: m
        real(kind=kind(1.0d0)), dimension(:), intent(out) :: ff
        integer :: n

        n = size(ff)
        ff = 0.0d0  ! Initialize the array to zeros
        m = 4

        do
            if (m < 1) exit
            ff(m) = 1.0d0
            m = m - 1
        end do
    end subroutine rysfun

end module ycwu_module

program ycwu_test
    use ycwu_module
    implicit none
    real(kind=kind(1.0d0)), dimension(13) :: ff
    integer :: i
    logical :: all_correct

    call rysfun(ff)

    all_correct = .true.
    do i = 1, 13
        if (i <= 4) then
            if (ff(i) /= 1.0d0) then
                all_correct = .false.
                exit
            end if
        else
            if (ff(i) /= 0.0d0) then
                all_correct = .false.
                exit
            end if
        end if
    end do

    if (all_correct) then
        print *, "Test Passed"
    else
        print *, "Test Failed"
    end if
end program ycwu_test