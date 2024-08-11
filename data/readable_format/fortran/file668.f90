! Define a module that contains the types
module types_mod
    implicit none

    ! Define the base type
    type, public :: baz_type
        integer :: id = 0
    end type baz_type

    ! Define the derived type
    type, public, extends(baz_type) :: meow_type
        integer :: special_id = 1
    end type meow_type

end module types_mod

! Define a program that uses the types module to perform tests
program test_inheritance
    use types_mod, only: meow_type
    implicit none

    type(meow_type) :: instance

    ! Set values for inherited and new member variables
    instance%id = 10  ! From baz_type
    instance%special_id = 20  ! From meow_type

    ! Print the values to verify inheritance and proper value assignment
    print *, "id from baz_type (inherited):", instance%id
    print *, "special_id from meow_type:", instance%special_id

end program test_inheritance