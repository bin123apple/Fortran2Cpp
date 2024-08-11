module ppm_module_mg_finalize

contains

    subroutine ppm_mg_finalize(kind)
        integer, intent(in) :: kind
        select case (kind)
        case (1)  ! __SINGLE_PRECISION
            print *, "Single precision, 2D, scalar field."
        case (2)  ! __DOUBLE_PRECISION
            print *, "Double precision, 2D, scalar field."
        case default
            print *, "Unsupported kind"
        end select
    end subroutine ppm_mg_finalize

end module ppm_module_mg_finalize

program test_ppm_mg_finalize
    use ppm_module_mg_finalize
    implicit none

    call ppm_mg_finalize(1)  ! Test single precision
    call ppm_mg_finalize(2)  ! Test double precision

end program test_ppm_mg_finalize