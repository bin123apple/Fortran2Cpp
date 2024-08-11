program testFoo
    implicit none
    integer :: testArray(4)
    
    ! Test case 1: Test with a mix of zero and non-zero elements
    testArray = (/0, 2, 0, 3/)
    call foo(testArray)
    call printArray(testArray)
    
    ! Test case 2: Test with all zeros
    testArray = (/0, 0, 0, 0/)
    call foo(testArray)
    call printArray(testArray)
    
    ! Test case 3: Test with all non-zeros
    testArray = (/4, 5, -1, 3/)
    call foo(testArray)
    call printArray(testArray)
    
contains

    subroutine foo(a)
        integer, dimension(4) :: a
        where (a(:4) .ne. 0)
            a(:4) = 1
        end where
    end subroutine foo
    
    subroutine printArray(a)
        integer, dimension(:), intent(in) :: a
        integer :: i
        do i=1, size(a)
            write(*,*) a(i)
        end do
    end subroutine printArray
    
end program testFoo