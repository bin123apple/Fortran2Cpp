program test_type_definitions
    implicit none
    type :: t1
        integer :: i
    end type t1

    type :: ts
        sequence
        integer :: j
    end type ts

    type(t1) :: x1
    type(ts) :: x2
    integer :: i

    ! Initialize variables
    x1%i = 10
    x2%j = 20
    i = 5

    ! Display values to demonstrate successful type definition and instance creation
    print *, "Value in x1%i: ", x1%i
    print *, "Value in x2%j: ", x2%j
    print *, "Value in i: ", i

end program test_type_definitions