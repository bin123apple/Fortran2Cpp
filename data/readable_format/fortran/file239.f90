! hello.f90
module hello_mod
contains
    subroutine sayHello
        print *, "Hello, World!"
    end subroutine sayHello
end module hello_mod

program hello
    use hello_mod
    call sayHello()
end program hello