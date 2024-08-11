module main_module
contains
    subroutine compute(arr)
        integer, intent(out) :: arr(0:32*32*32-1)
        integer :: i, j, k
        integer, target :: x
        integer, pointer :: p

        do i = 0, 32*32*32-1
            arr(i) = i
        end do

        !$acc kernels copy(arr)
        do i = 0, 31
            !$acc loop gang(num:32)
            do j = 0, 31
                p => x
                x = ieor(i, j * 3)
                
                !$acc loop worker(num:8) private(x, p)
                do k = 0, 31
                    arr(i * 1024 + j * 32 + k) = arr(i * 1024 + j * 32 + k) + x * k
                end do

                p = ior(i, j * 5)

                do k = 0, 31
                    arr(i * 1024 + j * 32 + k) = arr(i * 1024 + j * 32 + k) + x * k
                end do
            end do
        end do
        !$acc end kernels
    end subroutine compute
end module main_module

program test_main
    use main_module
    integer :: arr(0:32*32*32-1), i, j, k, idx

    call compute(arr)

    do i = 0, 31
        do j = 0, 31
            do k = 0, 31
                idx = i * 1024 + j * 32 + k
                if (arr(idx) /= idx + ieor(i, j * 3) * k + ior(i, j * 5) * k) then
                    print *, 'Test Failed at:', i, j, k
                    stop
                end if
            end do
        end do
    end do
    print *, 'All tests passed!'
end program test_main