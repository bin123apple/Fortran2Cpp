module hello_mod
    implicit none
contains
    subroutine printHelloWorld
        print '(" Hello, World")'
    end subroutine printHelloWorld
end module hello_mod

program hello
    use hello_mod
    implicit none
    call printHelloWorld
end program hello