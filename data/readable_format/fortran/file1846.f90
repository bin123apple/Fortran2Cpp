! sum0_module.f90
module sum0_module
    implicit none
contains
    function sum0_i(arr, mask) result(resultSum)
        integer, intent(in) :: arr(:)
        logical, intent(in) :: mask(:)
        integer :: resultSum
        integer :: i

        resultSum = 0
        do i = 1, size(arr)
            if (mask(i)) then
                resultSum = resultSum + arr(i)
            endif
        end do
    end function sum0_i
end module sum0_module

! test_sum0.f90
program test_sum0
    use sum0_module
    implicit none
    integer :: result
    integer, allocatable :: arr(:)
    logical, allocatable :: mask(:)

    ! Example data
    allocate(arr(4))
    allocate(mask(4))
    arr = (/1, 2, 3, 4/)
    mask = (/.true., .false., .true., .false./)

    ! Call the function
    result = sum0_i(arr, mask)
    print *, "Sum result: ", result

    ! Free allocated memory
    deallocate(arr)
    deallocate(mask)
end program test_sum0