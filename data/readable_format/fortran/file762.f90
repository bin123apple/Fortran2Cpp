! test_dat_node_mod.f90
module DAT_MOD
    implicit none
    type :: DAT
        integer :: NN
    contains
        procedure :: less_than => DAT_LT
    end type DAT
contains
    logical function DAT_LT(this, other)
        class(DAT), intent(in) :: this, other
        DAT_LT = this%NN < other%NN
    end function DAT_LT
end module DAT_MOD

module NODE_MOD
    use DAT_MOD
    implicit none
    type :: NODE
        integer :: KEY
        type(DAT), pointer :: PTR
    contains
        procedure :: less_than => NODE_LT
    end type NODE
contains
    logical function NODE_LT(this, other)
        class(NODE), intent(in) :: this, other
        if (this%KEY /= other%KEY) then
            NODE_LT = this%KEY < other%KEY
        else
            NODE_LT = this%PTR%NN < other%PTR%NN
        endif
    end function NODE_LT
end module NODE_MOD

program test_dat_node
    use DAT_MOD
    use NODE_MOD
    implicit none

    type(DAT) :: dat1, dat2
    type(NODE) :: node1, node2

    ! Initialize DAT instances
    dat1 = DAT(10)
    dat2 = DAT(20)

    ! Initialize NODE instances and their PTRs
    allocate(node1%PTR)
    allocate(node2%PTR)
    node1%KEY = 1
    node1%PTR%NN = 10
    node2%KEY = 2
    node2%PTR%NN = 20

    ! Test DAT comparison
    if (dat1%NN < dat2%NN) then
        print *, "DAT Test Passed."
    else
        print *, "DAT Test Failed."
    endif

    ! Test NODE comparison using the explicit function call
    if (NODE_LT(node1, node2)) then
        print *, "NODE Test Passed."
    else
        print *, "NODE Test Failed."
    endif

    ! Cleanup
    deallocate(node1%PTR, node2%PTR)
end program test_dat_node