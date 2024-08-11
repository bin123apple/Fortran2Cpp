! Define the subroutine outside of the main program unit
subroutine writeqnode(myid, qnode, qnodesize)
    implicit none
    integer :: i
    integer, intent(in) :: myid, qnodesize
    real*8, intent(in) :: qnode(qnodesize)
    character(len=20) :: filename

    ! Constructing the filename based on myid
    write(filename, '(I4)') 1000+myid

    ! Open the file for writing
    open(unit=1000+myid, file=trim(adjustl(filename)), status="replace", action="write")

    ! Writing to the file with the specified format
    do i = 1, qnodesize
        write(1000+myid, '(1x, E14.8)') qnode(i)
    end do

    ! Close the file after writing
    close(1000+myid)
end subroutine writeqnode

! Main program to test the subroutine
program test_writeqnode
    implicit none
    integer :: myid
    integer, parameter :: qnodesize = 5
    real*8 :: qnode(qnodesize)
    integer :: i

    ! Setup test values
    myid = 1
    do i = 1, qnodesize
        qnode(i) = i * 0.1
    end do

    ! Call the subroutine
    call writeqnode(myid, qnode, qnodesize)

    print *, "Test completed. Check the file corresponding to 1000+myid for output."
end program test_writeqnode