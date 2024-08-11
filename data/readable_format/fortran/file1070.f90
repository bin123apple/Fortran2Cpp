module mod_xghis1
    implicit none
    integer, parameter :: nelemg = 100
    real :: xargat(nelemg)
contains
    subroutine xghis1(a, ln, nft, nlt)
        integer, intent(in) :: ln, nft, nlt
        real, dimension(ln, *) :: a
        integer :: i

        ! Initialize xargat to zero
        xargat = 0.0

        do i = nft, nlt
            xargat(i) = a(1,i)
        end do
    end subroutine xghis1
end module mod_xghis1

program test_xghis1
    use mod_xghis1
    implicit none
    real, dimension(10, nelemg) :: a
    integer :: ln, nft, nlt, i

    ln = 10
    nft = 1
    nlt = 5

    ! Initialize a to zero and set test values
    a = 0.0
    do i = nft, nlt
        a(1, i) = real(i)
    end do

    ! Call the subroutine
    call xghis1(a, ln, nft, nlt)

    ! Check results
    do i = 1, nelemg
        if (i >= nft .and. i <= nlt) then
            if (xargat(i) /= real(i)) then
                print *, "Fortran Test failed for index: ", i
                stop
            end if
        else
            if (xargat(i) /= 0.0) then
                print *, "Fortran Test failed for index: ", i
                stop
            end if
        end if
    end do

    print *, "Fortran: All tests passed."
end program test_xghis1