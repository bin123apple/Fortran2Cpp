program test_allocation
    implicit none
    integer :: nat, npertx
    real, allocatable :: t(:,:,:,:), tmq(:,:,:)

    nat = 10    ! Example value
    npertx = 5  ! Example value

    call allocate_pert
    call deallocate_pert

contains

    subroutine allocate_pert()
        implicit none
        allocate ( t ( npertx, npertx, 48, 3 * nat ) )
        allocate ( tmq ( npertx, npertx, 3 * nat ) )
    end subroutine allocate_pert

    subroutine deallocate_pert()
        implicit none
        if (allocated(t)) deallocate ( t )
        if (allocated(tmq)) deallocate ( tmq )
    end subroutine deallocate_pert

end program test_allocation