module Data_Type_Cell
! Assuming necessary modules would be defined here or simplified
use, intrinsic :: iso_fortran_env, only: real64
implicit none
private

type, public :: Type_Vector
    real(real64) :: x = 0.0_real64, y = 0.0_real64, z = 0.0_real64
end type Type_Vector

type, public :: Type_Primitive
    real(real64) :: someValue = 0.0_real64
    contains
        procedure :: free => free_primitive
        procedure :: init => init_primitive
end type Type_Primitive

type, public :: Type_Conservative
    real(real64) :: anotherValue = 0.0_real64
    contains
        procedure :: free => free_conservative
        procedure :: init => init_conservative
end type Type_Conservative

type, public :: Type_Cell
    real(real64) :: V = 0.0_real64
    type(Type_Vector) :: cent
    real(real64) :: Dt = 0.0_real64
    type(Type_Primitive) :: P
    type(Type_Conservative) :: U
    type(Type_Conservative), allocatable :: KS(:)
    contains
        procedure :: init => init_cell
        procedure :: free => free_cell
end type Type_Cell

type, public :: Type_Cell_Ptr
    type(Type_Cell), pointer :: p => null()
end type Type_Cell_Ptr

contains

    subroutine free_primitive(this)
        class(Type_Primitive), intent(inout) :: this
        this%someValue = 0.0_real64
    end subroutine free_primitive

    subroutine init_primitive(this)
        class(Type_Primitive), intent(inout) :: this
        this%someValue = 1.0_real64 ! Just an example action
    end subroutine init_primitive

    subroutine free_conservative(this)
        class(Type_Conservative), intent(inout) :: this
        this%anotherValue = 0.0_real64
    end subroutine free_conservative

    subroutine init_conservative(this)
        class(Type_Conservative), intent(inout) :: this
        this%anotherValue = 1.0_real64 ! Just an example action
    end subroutine init_conservative

    subroutine free_cell(cell)
        class(Type_Cell), intent(inout) :: cell

        call cell%P%free
        call cell%U%free
        if (allocated(cell%KS)) deallocate(cell%KS)
    end subroutine free_cell

    subroutine init_cell(cell, rk_ord)
        class(Type_Cell), intent(inout) :: cell
        integer, intent(in) :: rk_ord

        if (allocated(cell%KS)) deallocate(cell%KS)
        allocate(cell%KS(rk_ord))
    end subroutine init_cell

end module Data_Type_Cell

program test_Data_Type_Cell
use Data_Type_Cell
implicit none

    type(Type_Cell) :: cell
    type(Type_Primitive) :: prim
    type(Type_Conservative) :: cons

    ! Initialize a Type_Cell with dummy values to be able to test freeing functionality
    call cell%init(2)
    call cell%free()

    ! Test that KS is deallocated properly
    if (.not. allocated(cell%KS)) then
        print *, "free_cell test passed."
    else
        print *, "free_cell test failed."
    endif

end program test_Data_Type_Cell