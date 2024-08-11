program testProgram
    implicit none

    call subroutineExample()
    print *, "Result from functionExample: ", functionExample(5)

contains

    subroutine subroutineExample()
        print *, "Hello from subroutineExample!"
    end subroutine subroutineExample

    function functionExample(x) result(y)
        integer, intent(in) :: x
        integer :: y
        y = 2 * x
    end function functionExample

end program testProgram