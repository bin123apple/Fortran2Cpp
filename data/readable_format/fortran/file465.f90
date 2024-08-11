program test_recoverC
    implicit none

    ! Define constants directly in the program
    integer, parameter :: ME2c_max = 100
    integer, parameter :: nsh_max = 10

    real, dimension(ME2c_max) :: hlist, dhlist
    real, dimension(nsh_max, nsh_max) :: hbox, dhbox
    integer :: n1, n2
    integer :: i, j

    ! Initialize arrays to 0
    hlist = 0.0
    dhlist = 0.0
    hbox = 0.0
    dhbox = 0.0

    ! Initialize test case
    n1 = 2
    n2 = 3
    ! Assign values to the first 6 elements of hlist and dhlist
    hlist(1:6) = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0]
    dhlist(1:6) = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6]

    ! Call the subroutine
    call recoverC(n1, n2, hlist, dhlist, hbox, dhbox)

    ! Output results for verification
    do i = 1, n1
        do j = 1, n2
            print *, "hbox(", i, ",", j, ") = ", hbox(i, j)
            print *, "dhbox(", i, ",", j, ") = ", dhbox(i, j)
        end do
    end do

contains

    subroutine recoverC (n1, n2, hlist, dhlist, hbox, dhbox)
        implicit none

        integer, intent (in) :: n1, n2

        real, intent(in), dimension (ME2c_max) :: hlist 
        real, intent(in), dimension (ME2c_max) :: dhlist 

        real, intent(out), dimension (nsh_max, nsh_max) :: hbox
        real, intent(out), dimension (nsh_max, nsh_max) :: dhbox

        integer :: index
        integer :: indexcoulomb
        integer :: ii
        integer :: kk

        ii = 1
        kk = 0

        indexcoulomb = n1*n2
        do index = 1, indexcoulomb
            kk = kk + 1
            hbox(ii,kk) = hlist(index)
            dhbox(ii,kk) = dhlist(index)
            if (mod(index,n2) .eq. 0) then
                ii = ii + 1
                kk = kk - n2
            end if
        end do

    end subroutine recoverC

end program test_recoverC