module mymodule
    implicit none
    type :: t
        character :: c
    end type t
contains
    function init_type(c) result(instance)
        character, intent(in) :: c
        type(t) :: instance
        instance%c = c
    end function init_type
end module mymodule

program p
    use mymodule
    implicit none
    type(t) :: instance
    character :: x

    instance = init_type('a')
    x = instance%c
    print *, 'Value of x:', x
end program p