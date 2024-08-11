program main
    implicit none
    type t
       integer, pointer, dimension(:,:) :: n
    end type t

    type(t) :: left
    integer, target, dimension(4,4) :: right
    integer :: i, j
    logical :: test_passed

    right = 4
    left%n => right

    ! Simple test to verify the pointer association
    test_passed = .TRUE.
    do i = 1, 4
        do j = 1, 4
            if (left%n(i, j) /= right(i, j)) then
                test_passed = .FALSE.
                exit
            endif
        enddo
        if (.NOT. test_passed) exit
    enddo

    if (test_passed) then
        print *, "Test passed: left%n points to right and has correct values."
    else
        print *, "Test failed."
    endif
end program main