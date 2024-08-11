module networks
    implicit none
contains
    subroutine normal(arr)
        real, intent(inout) :: arr(:,:,:)
        integer :: i, j, k, n1, n2, n3
        n1 = size(arr, 1)
        n2 = size(arr, 2)
        n3 = size(arr, 3)
        do k = 1, n3
            do j = 1, n2
                do i = 1, n1
                    if (arr(i, j, k) /= 0.0) then
                        arr(i, j, k) = 1.0 / arr(i, j, k)
                    end if
                end do
            end do
        end do
    end subroutine normal

    function calc_distance(laplacian, node1, node2) result(distance)
        real, intent(in) :: laplacian(:,:)
        integer, intent(in) :: node1, node2
        real :: distance

        if (node1 < 1 .or. node2 < 1 .or. node1 > size(laplacian, 1) .or. node2 > size(laplacian, 2)) then
            print *, "Error: Node index out of bounds."
            distance = -1.0
        else
            distance = sqrt(abs(laplacian(node1, node2)))
        end if
    end function calc_distance
end module networks

program test_networks
    use networks
    implicit none
    real :: arr(2,2,2), laplacian(2,2), dist
    integer :: i, j, k

    ! Initialize and test the normal subroutine
    arr = reshape([(i, i=1,8)], [2,2,2])
    call normal(arr)
    print *, "After normalizing:"
    do k = 1, 2
        print *, "Layer", k
        do j = 1, 2
            print *, (arr(i,j,k), i=1,2)
        end do
    end do

    ! Initialize and test the calc_distance function
    laplacian = reshape([0.0, 1.0, 1.0, 0.0], [2,2])
    dist = calc_distance(laplacian, 1, 2)
    print *, "Distance between node 1 and 2:", dist
end program test_networks