module convolution_mod
    implicit none
    private
    public :: apply

contains

subroutine apply(C)
    integer, intent(inout) :: C(:, :, :)
    integer, allocatable :: C2(:,:,:)
    integer :: k(3, 3)
    integer :: i, j, o, w, h, sum_k

    k = reshape([-4, -2, 0, -2, 1, 2, 0, 2, 4], [3, 3])
    w = size(C, 2)
    h = size(C, 3)
    allocate(C2(size(C, 1), size(C, 2), size(C, 3)))

    C2 = C
    do o = 1, size(C, 1)
        do j = 2, h-1
            do i = 2, w-1
                sum_k = sum(k)
                if (sum_k /= 0) then
                    C2(o, i, j) = sum(C(o, i-1:i+1, j-1:j+1) * k) / sum_k
                end if
            end do
        end do
    end do
    C = C2

    where(C < 0) C = 0
    where(C > 255) C = 255
end subroutine

end module

program test_convolution
    use convolution_mod
    implicit none

    integer :: C(3, 3, 3)
    integer :: i, j, k

    C = reshape([10, 20, 30, 40, 50, 60, 70, 80, 90, &
                 15, 25, 35, 45, 55, 65, 75, 85, 95, &
                 20, 30, 40, 50, 60, 70, 80, 90, 100], [3, 3, 3])

    call apply(C)

    do k = 1, size(C, 1)
        do j = 1, size(C, 2)
            do i = 1, size(C, 3)
                print *, 'C(', k, ',', j, ',', i, ') = ', C(k, j, i)
            end do
        end do
    end do

end program test_convolution