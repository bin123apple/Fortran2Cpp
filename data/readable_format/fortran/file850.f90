program test_dawrit
    implicit none
    real(8), allocatable :: arr(:)
    integer :: n

    ! Define the array length and allocate it
    n = 5
    allocate(arr(n))
    arr = [1.0, 2.0, 3.0, 4.0, 5.0]

    ! Call the dawrit subroutine
    call dawrit(arr, n, 1)

contains

    subroutine dawrit(V, LEN, NREC)
        integer, intent(in) :: LEN, NREC
        real(8), dimension(LEN), intent(in) :: V
        real(8) :: sum
        integer :: i

        sum = 0.0
        do i = 1, LEN
            sum = sum + V(i)
        end do
        print *, 'Sum = ', sum
    end subroutine dawrit

end program test_dawrit