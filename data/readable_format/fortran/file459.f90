program testArrayInitialization
    implicit none
    integer, dimension(2,2) :: nums
    character(len=2), dimension(2,2) :: s2s
    integer :: i, j
    logical :: testPassed

    ! Initialize arrays
    nums = reshape([12, 34, 56, 78], shape(nums))
    s2s = reshape([character(len=2) :: 'Xy', 'Za', 'cD', 'eF'], shape(s2s))

    ! Output arrays
    do i = 1, 2
        do j = 1, 2
            write(*, '(i2, x, a)') nums(i,j), s2s(i,j)
        end do
    end do

    ! Simple testing
    testPassed = .true.
    if (nums(1,1) /= 12) testPassed = .false.
    if (nums(2,2) /= 78) testPassed = .false.
    if (s2s(1,1) /= 'Xy') testPassed = .false.
    if (s2s(2,2) /= 'eF') testPassed = .false.

    if (testPassed) then
        write(*,*) 'Test passed.'
    else
        write(*,*) 'Test failed.'
    end if

end program testArrayInitialization