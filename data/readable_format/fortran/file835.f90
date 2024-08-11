program test_per_out2
    implicit none
    double precision, allocatable :: input(:,:), output(:,:)
    integer :: n, m

    ! Test 1: All elements in the third row are non-zero
    n = 3
    m = 3
    allocate(input(3,n))
    allocate(output(3,m))
    input = reshape([1d0, 2d0, 3d0, 4d0, 5d0, 6d0, 7d0, 8d0, 9d0], shape(input))
    call per_out2(input, n, output, m)
    call print_output(output, m)

    ! Reset arrays for next test
    deallocate(input)
    deallocate(output)

    ! Test 2: Some elements in the third row are zero
    n = 3
    m = 3 ! Initially allocate more space than needed
    allocate(input(3,n))
    allocate(output(3,m))
    input = reshape([1d0, 2d0, 3d0, 4d0, 5d0, 6d0, 7d0, 0d0, 0d0], shape(input))
    call per_out2(input, n, output, m)
    call print_output(output, m)

    ! Reset arrays for next test
    deallocate(input)
    deallocate(output)

    ! Test 3: All elements in the third row are zero
    n = 3
    m = 3 ! Initially allocate more space than needed
    allocate(input(3,n))
    allocate(output(3,m))
    input = reshape([1d0, 2d0, 3d0, 4d0, 5d0, 6d0, 0d0, 0d0, 0d0], shape(input))
    call per_out2(input, n, output, m)
    call print_output(output, m)

    ! Cleanup
    deallocate(input)
    deallocate(output)

contains

    subroutine per_out2(in,n,out,m)
        implicit none
        double precision, intent(in) :: in(3,n)
        double precision, intent(out) :: out(3,m)
        integer, intent(in) :: n, m
        integer :: jo, j, i
        jo=0

        do j=1,n
            if (in(3,j).ne.0.0) then
                jo=jo+1

                if (jo > m) then
                    print *, "Output array is too small for the filtered data."
                    return
                end if

                do i=1,3
                    out(i,jo)=in(i,j)
                end do
            end if
        end do

        if (jo < m) then
            print *, "Output array is larger than non-zero columns. Only ", jo, " columns are filled."
        end if
    end subroutine per_out2

    subroutine print_output(out, m)
        double precision, intent(in) :: out(3,*)
        integer, intent(in) :: m
        integer :: i, j

        if (m == 0) then
            print *, "No output (all elements were zero)."
            return
        end if

        do j=1,m
            write(*,*) (out(i,j), i=1,3)
        end do
        write(*,*) '---'
    end subroutine print_output

end program test_per_out2