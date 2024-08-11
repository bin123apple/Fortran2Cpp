program testGA3019
implicit none
    call testGA3019Behavior
contains
    subroutine testGA3019Behavior()
        call GA3019(1, 2, 3, 4)
        print *, 'testGA3019Behavior passed.'
    end subroutine testGA3019Behavior

    subroutine GA3019(nf1, nf2, nf3, nf4)
        integer :: nf1, nf2, nf3, nf4, i, j
        integer, allocatable :: ida(:,:), ida1(:,:,:)

        allocate(ida(nf2,nf3))
        allocate(ida1(nf2,nf4,nf3))

        ida1 = 3
        ida = -3

        do i = nf1, nf2
            do j = nf1, nf3
                ida(i,j) = PRODUCT(ida1,nf2, nf1 .LT. 0)
            end do
        end do

        if (any(ida /= 1)) then
            print *, 'Abort condition met, this is a placeholder message.'
            ! call abort
        endif

        deallocate(ida)
        deallocate(ida1)
    end subroutine GA3019

    integer function PRODUCT(ida1, nf2, condition)
        integer, intent(in) :: ida1(:,:,:), nf2
        logical, intent(in) :: condition
        PRODUCT = 1
    end function PRODUCT
end program testGA3019