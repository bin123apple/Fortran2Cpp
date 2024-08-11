program test_checksum
    implicit none

    double precision, allocatable :: array(:)
    character(len=20) :: tag
    integer :: n

    ! Test case 1
    tag = 'Test 1'
    n = 3
    allocate(array(n))
    array = [1.0d0, 2.0d0, 3.0d0]
    call checksum(tag, array, n)
    deallocate(array)

    ! Test case 2
    tag = 'Test 2'
    n = 4
    allocate(array(n))
    array = [0.5d0, 1.5d0, -2.0d0, 0.0d0]
    call checksum(tag, array, n)
    deallocate(array)

    ! Add more test cases as needed

contains

    subroutine checksum(sTag, a, n)
        implicit none
        
        character(len=*) :: sTag
        integer :: n
        double precision, dimension(n) :: a
        
        double precision :: sm, nm
        integer :: i

        sm = 0.d0
        nm = 0.d0
        do i = 1, n
            sm = sm + a(i)
            nm = nm + a(i) * a(i)
        end do
        write(*, '(A, A, 1X, 2E30.16)') '@CHECKSUM: ', sTag, sm, sqrt(nm)

    end subroutine checksum

end program test_checksum