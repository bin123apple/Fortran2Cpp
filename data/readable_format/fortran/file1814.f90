program write_2d_array
    implicit none
    integer, parameter :: m=10, n=5, i=3, nrow=4
    double precision, dimension(m,n) :: array
    integer :: j, k

    ! Initialize the array with some data for demonstration
    do j = 1, m
        do k = 1, n
            array(j, k) = sin(real(j * k))
        end do
    end do

    ! Write a portion of the array to a file
    call write_portion_to_file('output.txt', m, n, i, nrow, array)
end program write_2d_array

subroutine write_portion_to_file(filename, m, n, i, nrow, array)
    implicit none
    character(len=*), intent(in) :: filename
    integer, intent(in) :: m, n, i, nrow
    double precision, dimension(m,n), intent(in) :: array
    integer :: j, k
    open(unit=10, file=filename, status='replace', action='write')

    ! Write the specified portion of the array to the file
    do j = i, i+nrow-1
        if (j > m) exit ! Ensure we don't go out of bounds
        do k = 1, n
            write(10, '(*(F10.5))') array(j, k)
        end do
    end do
    close(unit=10)
end subroutine write_portion_to_file