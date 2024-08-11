program main
    implicit none
    call testHelloWorld
contains
    subroutine testHelloWorld
        implicit none
        character(len=13) :: expectedOutput
        expectedOutput = "Hello, World!"
        write(*, '(A)') expectedOutput
    end subroutine testHelloWorld
end program main