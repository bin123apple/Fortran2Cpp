module Storage_module
    implicit none
    private
    public :: Storage_t, newStorage

    ! Assuming RP is a kind parameter for real numbers.
    integer, parameter :: RP = selected_real_kind(15, 307)
    integer, parameter :: NCONS = 5
    
    ! Define a logical parameter to simulate NAVIER_STOKES being defined or not.
    logical, parameter :: isNavierStokes = .true.

#ifdef NAVIER_STOKES
    integer, parameter :: NDIM = 3
#endif

    type Storage_t
        real(kind=RP), allocatable :: Q(:)
        real(kind=RP), allocatable :: QDot(:)
#ifdef NAVIER_STOKES
        real(kind=RP), allocatable :: dQ(:)
#endif
    contains
        procedure :: AllocateMemory => Storage_AllocateMemory
    end type Storage_t

contains

    function newStorage() result(val)
        type(Storage_t) :: val
        ! Initialize pointers as not allocated
        allocate(val%Q(0))
        allocate(val%QDot(0))
#ifdef NAVIER_STOKES
        allocate(val%dQ(0))
#endif
    end function newStorage

    subroutine Storage_AllocateMemory(self, totalPolynomialOrder)
        class(Storage_t), intent(inout) :: self
        integer, intent(in) :: totalPolynomialOrder

        allocate(self%Q(NCONS * totalPolynomialOrder))
        self%Q = 0.0_RP
        allocate(self%QDot(NCONS * totalPolynomialOrder))
        self%QDot = 0.0_RP
#ifdef NAVIER_STOKES
        allocate(self%dQ(NCONS * NDIM * totalPolynomialOrder))
        self%dQ = 0.0_RP
#endif
    end subroutine Storage_AllocateMemory

end module Storage_module

program testStorage
    use Storage_module
    implicit none
    type(Storage_t) :: storage
    integer :: totalPolynomialOrder

    totalPolynomialOrder = 10
    storage = newStorage()
    call storage%AllocateMemory(totalPolynomialOrder)

    ! Output to demonstrate allocations
    print *, 'Q allocated with size:', size(storage%Q)
    print *, 'QDot allocated with size:', size(storage%QDot)
#ifdef NAVIER_STOKES
    print *, 'dQ allocated with size:', size(storage%dQ)
#else
    print *, 'NAVIER_STOKES is not defined; dQ not allocated.'
#endif
end program testStorage