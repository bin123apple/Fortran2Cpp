subroutine MRE_DECOMP1D(n, numprocs, myid, s, e)
    integer, intent(in) :: n, numprocs, myid
    integer, intent(out) :: s, e
    integer :: nlocal, deficit

    nlocal = n / numprocs
    s = myid * nlocal + 1
    deficit = mod(n, numprocs)
    s = s + min(myid, deficit)
    if (myid < deficit) then
        nlocal = nlocal + 1
    endif
    e = s + nlocal - 1
    if (e > n .or. myid == numprocs-1) e = n
end subroutine MRE_DECOMP1D

program test_decomp
    implicit none
    integer :: s, e

    ! Test cases
    call test(100, 10, 0, s, e) ! Even division
    call test(100, 3, 0, s, e)  ! Uneven division, first process
    call test(100, 3, 2, s, e)  ! Last process
    call test(100, 1, 0, s, e)  ! Single process
    call test(5, 10, 0, s, e)   ! More processes than elements, first active
    call test(5, 10, 6, s, e)   ! Inactive process

contains
    subroutine test(n, numprocs, myid, s, e)
        integer, intent(in) :: n, numprocs, myid
        integer, intent(out) :: s, e
        call MRE_DECOMP1D(n, numprocs, myid, s, e)
        print *, 'n:', n, 'procs:', numprocs, 'id:', myid, 'start:', s, 'end:', e
    end subroutine test
end program test_decomp