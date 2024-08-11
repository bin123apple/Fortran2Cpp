program Main
    implicit none
    integer :: lwin
    double precision :: theta0, alpha
    integer :: m, taper_number

    ! Example input values
    theta0 = 30.0d0
    m = 2
    alpha = 0.5d0
    taper_number = 1

    lwin = SHFindLWin(theta0, m, alpha, taper_number)
    print *, "LWin:", lwin

contains

    integer function SHFindLWin(theta0, m, alpha, taper_number)
        implicit none
        double precision, intent(in) :: theta0, alpha
        integer, intent(in) :: m
        integer, intent(in) :: taper_number
        double precision :: pi, alpha1
        integer :: l, astat(2), tn
        double precision, allocatable :: dllm(:,:), eval(:)

        pi = acos(-1.0d0)
        tn = taper_number
        l = tn

        do
            l = l + 1
            allocate(dllm(l+1,l+1), stat = astat(1))
            dllm = 0.0d0
            allocate(eval(l+1), stat = astat(2))
            eval = 0.0d0

            ! Simplified operations just for demonstration
            if (m == 0) then
                call ComputeD0(dllm, l, theta0)
            else
                call ComputeDm(dllm, l, abs(m), theta0)
            endif

            call EigValSym(dllm, l+1, eval)

            alpha1 = eval(tn)

            deallocate(dllm)
            deallocate(eval)

            if (alpha1 >= alpha) then
                SHFindLWin = l
                return
            endif
        end do
    end function SHFindLWin

    ! Placeholder for ComputeDm
    subroutine ComputeDm(dllm, l, m, theta0)
        double precision, intent(inout) :: dllm(:,:)
        integer, intent(in) :: l, m
        double precision, intent(in) :: theta0
        ! Simplified implementation
    end subroutine ComputeDm

    ! Placeholder for ComputeD0
    subroutine ComputeD0(dllm, l, theta0)
        double precision, intent(inout) :: dllm(:,:)
        integer, intent(in) :: l
        double precision, intent(in) :: theta0
        ! Simplified implementation
    end subroutine ComputeD0

    ! Placeholder for EigValSym
    subroutine EigValSym(dllm, n, eval)
        double precision, intent(in) :: dllm(:,:)
        integer, intent(in) :: n
        double precision, intent(out) :: eval(:)
        ! Simplified implementation
        eval = 0.5  ! Example to change alpha1 for testing
    end subroutine EigValSym

end program Main