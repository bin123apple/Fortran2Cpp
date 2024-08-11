module MOD_EXTURAY
contains
    subroutine extUray(U, Uray, nd, np, iray)
        implicit none
        real*8, intent(in) :: U(:,:)
        real*8, intent(out) :: Uray(:)
        integer, intent(in) :: nd, np, iray
        integer :: L
        
        do L = 1, nd
            Uray(L) = U(L, iray)
        end do
    end subroutine extUray
end module MOD_EXTURAY

program test_extUray
    use MOD_EXTURAY
    implicit none
    real*8, allocatable :: U(:,:), Uray(:)
    integer :: nd, np, iray

    nd = 4
    np = 3
    iray = 2

    ! Allocate and initialize U
    allocate(U(nd,np))
    allocate(Uray(nd))
    U = reshape([1.0d0, 2.0d0, 3.0d0, &
                 4.0d0, 5.0d0, 6.0d0, &
                 7.0d0, 8.0d0, 9.0d0, &
                 10.0d0, 11.0d0, 12.0d0], shape(U), order=[2,1])
    
    ! Call the subroutine
    call extUray(U, Uray, nd, np, iray)

    ! Display results
    print *, "Extracted column (iray=", iray, "):"
    print *, Uray

    ! Clean up
    deallocate(U)
    deallocate(Uray)
end program test_extUray