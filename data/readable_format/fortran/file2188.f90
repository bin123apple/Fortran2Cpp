program test_threshold_image
    implicit none
    integer, parameter :: n = 3
    real(8) :: image(n, n), output(n, n)
    real(8) :: threshold
    integer :: i, j

    ! Initialize the image with some values
    image = reshape([0.1, 0.6, 0.3, 0.7, 0.4, 0.8, 0.5, 0.2, 0.9], shape(image))

    ! Set the threshold value
    threshold = 0.5

    ! Call the subroutine
    call threshold_image(image, n, threshold, output)

    ! Print the output to verify correctness
    print *, 'Output image:'
    do i = 1, n
        do j = 1, n
            print *, output(i, j)
        end do
        print *, '' ! For a new line after each row
    end do
end program test_threshold_image

subroutine threshold_image(image, n, threshold, output)
    integer, intent(in) :: n
    real(8), intent(in) :: threshold
    real(8), dimension(n,n), intent(in) :: image
    real(8), dimension(n,n), intent(out) :: output
    integer :: i, j

    write(*,*) "Hello from the Fortran subroutine!"

    do i = 1, n
        do j = 1, n
            if (image(i,j) > threshold) then
                output(i,j) = 1.0
            else
                output(i,j) = 0.0
            end if
        end do
    end do
end subroutine threshold_image