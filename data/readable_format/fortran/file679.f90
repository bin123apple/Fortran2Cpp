program test_count_w_lp5
    implicit none
    integer, dimension(4) :: rext = [10, 10, 10, 10]
    integer, dimension(5) :: sext = [10, 10, 10, 10, 10]
    integer, dimension(4) :: blkcnts = [2, 2, 2, 2]
    integer, dimension(4) :: lmext = [5, 5, 5, 5]
    integer, dimension(:,:,:,:), allocatable :: result
    logical, dimension(:,:,:,:,:), allocatable :: source
    integer :: npes = 1
    integer :: dist_cnt
    integer, dimension(:), allocatable :: hi1, low1, hi2, low2, hi3, low3, hi4, low4
    integer :: i, j, k, l

    ! Initialize arrays
    allocate(hi1(blkcnts(1)), low1(blkcnts(1)))
    allocate(hi2(blkcnts(2)), low2(blkcnts(2)))
    allocate(hi3(blkcnts(3)), low3(blkcnts(3)))
    allocate(hi4(blkcnts(4)), low4(blkcnts(4)))
    allocate(source(sext(1), sext(2), sext(3), sext(4), sext(5)))
    allocate(result(rext(1), rext(2), rext(3), rext(4)))

    source = .true.

    ! Call the subroutine
    call COUNT_W_LP5(result, source, 4, rext, sext, blkcnts, npes, &
        hi1, low1, hi2, low2, hi3, low3, hi4, low4, lmext, dist_cnt)

    ! Check results (example check, adjust according to your logic)
    print *, 'Test Case 1: Checking initialized values...'
    do i = 1, rext(1)
        do j = 1, rext(2)
            do k = 1, rext(3)
                do l = 1, rext(4)
                    if (result(i, j, k, l) /= 0) then
                        print *, 'Test Failed at', i, j, k, l
                        stop
                    endif
                end do
            end do
        end do
    end do
    print *, 'Test Passed.'

end program test_count_w_lp5

subroutine COUNT_W_LP5(result, source, dim, rext, sext, blkcnts, npes, hi1, low1, hi2, low2, hi3, low3, hi4, low4, lmext, dist_cnt)
    implicit none
    integer, intent(in) :: dim, npes, blkcnts(4), rext(4), sext(5), lmext(4)
    integer, intent(out) :: dist_cnt
    integer, dimension(rext(1),rext(2),rext(3),rext(4)), intent(inout) :: result
    logical, dimension(sext(1),sext(2),sext(3),sext(4),sext(5)), intent(in) :: source
    integer, dimension(blkcnts(1)), intent(in) :: hi1, low1
    integer, dimension(blkcnts(2)), intent(in) :: hi2, low2
    integer, dimension(blkcnts(3)), intent(in) :: hi3, low3
    integer, dimension(blkcnts(4)), intent(in) :: hi4, low4

    integer :: i4, i3, i2, i1

    ! Example logic to initialize 'result' array
    do i4 = 1, rext(4)
        do i3 = 1, rext(3)
            do i2 = 1, rext(2)
                do i1 = 1, rext(1)
                    result(i1,i2,i3,i4) = 0
                end do
            end do
        end do
    end do

    dist_cnt = 0 ! Example assignment, replace with actual logic
end subroutine COUNT_W_LP5