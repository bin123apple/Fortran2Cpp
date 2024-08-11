program testPrintArray
    implicit none
    ! Call the subroutine that performs the operation to be tested
    call printArray()
end program testPrintArray

subroutine printArray()
    character(len=2), dimension(2) :: arr = ['a ', 'bb']  ! Adjusted to have consistent element lengths
    print *, arr
end subroutine printArray