program test_selci_isum
    implicit none

    integer :: n, im
    parameter (n=3, im=2)
    integer :: m(im, n)
    integer :: result

    ! Initialize the matrix
    m(1, 1) = 1
    m(1, 2) = 2
    m(1, 3) = 3
    m(2, 1) = 4
    m(2, 2) = 5
    m(2, 3) = 6

    ! Call the function and print the result
    result = selci_isum(n, m, im)
    print *, "Test Result: ", result

    contains

        integer function selci_isum(n,m,im)
            integer, intent(in) :: n, im
            integer, intent(in) :: m(im,*)
            integer :: is, i

            is = 0
            do i = 1,n
                is = is + m(1,i)
            end do

            selci_isum = is
        end function selci_isum

end program test_selci_isum