module mod1
contains
    subroutine foo(a)
        real :: a
        print *, 'In mod1::foo with value ', a
    end subroutine foo
end module mod1

module mod2
contains
    subroutine bar(a)
        real :: a
        print *, 'In mod2::bar with value ', a
    end subroutine bar
end module mod2

program main
    use mod1, only: foo
    use mod2, only: bar

    call foo(1.0)
    call bar(2.0)
end program main