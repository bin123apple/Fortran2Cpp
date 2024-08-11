module owner_module
    implicit none
contains
    integer function owner_block(ig, nx, np)
        integer :: ig, nx, np, r, q

        q = nx / np
        r = mod(nx, np)

        if (ig <= ((q + 1) * r)) then
            owner_block = (ig - 1) / (q + 1)
        else
            owner_block = ((ig - 1 - r) / q) + r
        end if
    end function owner_block

    integer function owner_cyclic(ig, nx, np)
        integer :: ig, nx, np

        owner_cyclic = mod(ig - 1, np)
    end function owner_cyclic

    integer function owner_block_cyclic(indxglob, nb, nprocs)
        integer :: indxglob, nb, nprocs, indxg2p

        indxg2p = mod((indxglob - 1) / nb, nprocs)

        owner_block_cyclic = indxg2p
    end function owner_block_cyclic
end module owner_module

program test_owner_functions
    use owner_module
    implicit none

    call test_owner_block()
    call test_owner_cyclic()
    call test_owner_block_cyclic()

contains
    subroutine test_owner_block()
        integer :: ig, nx, np
        ig = 5
        nx = 20
        np = 4
        print *, 'owner_block(5, 20, 4) = ', owner_block(ig, nx, np)
    end subroutine test_owner_block

    subroutine test_owner_cyclic()
        integer :: ig, nx, np
        ig = 5
        nx = 20
        np = 4
        print *, 'owner_cyclic(5, 20, 4) = ', owner_cyclic(ig, nx, np)
    end subroutine test_owner_cyclic

    subroutine test_owner_block_cyclic()
        integer :: ig, nb, nprocs
        ig = 5
        nb = 4
        nprocs = 4
        print *, 'owner_block_cyclic(5, 4, 4) = ', owner_block_cyclic(ig, nb, nprocs)
    end subroutine test_owner_block_cyclic
end program test_owner_functions