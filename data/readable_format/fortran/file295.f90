! Assuming a simple precision model for demonstration
module Precision_Model
    implicit none
    integer, parameter :: stnd = selected_real_kind(p=15, r=307)
end module Precision_Model

module internal_types
    use Precision_Model
    implicit none

    public :: integrator_info, collection_info, user_info, epsalg_mem
    public :: Simplex, Hyperrectangle, EPSTABLENGHT

    integer, parameter :: Simplex = 1, Hyperrectangle = 2, EPSTABLENGHT = 52

    type :: integrator_info
        integer :: key, nrsub
        real(kind=stnd) :: tune
        logical :: uniform_subdiv
    end type integrator_info

    type :: collection_info
        integer :: dimens, nrvert, niinfo, nrinfo
    end type collection_info

    type :: user_info
        integer :: numfun, numrgn, minpts, maxpts
        real(kind=stnd) :: epsabs, epsrel
        logical :: restart
        integer :: neval, ifail
    end type user_info

    type :: epsalg_mem
        logical :: HEURISTIC_USED
        integer :: DIVLEVEL
        integer, pointer, dimension(:) :: NRRCOPY
        real(kind=stnd) :: ERRORMAXPOOL, EPSABS, EPSREL
        real(kind=stnd), pointer, dimension(:) :: ERLARG, RESULT1, ABSERR1
        real(kind=stnd), pointer, dimension(:,:) :: RCOPY, RESLA
    end type epsalg_mem

end module internal_types

program test_internal_types
    use internal_types
    implicit none

    ! Example test variables
    type(integrator_info) :: int_info
    type(collection_info) :: col_info
    type(user_info) :: usr_info
    type(epsalg_mem) :: eps_info

    ! Example test code here
    print *, 'This is a test program.'

    ! Initialize variables, perform operations, etc.
    ! Example: Setting and printing a value from integrator_info
    int_info%key = 10
    print *, 'int_info%key = ', int_info%key
end program test_internal_types