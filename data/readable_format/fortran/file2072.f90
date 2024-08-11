module types
    implicit none
    private :: AUXILIARY
    public :: person, kids, NUMERIC_SEQ, POINT

    type :: person
        character(len=20) :: forename
        integer :: age
    end type person

    type :: kids
        type(person) :: oldest_child
        type(person), allocatable, dimension(:) :: other_kids
    end type kids

    type :: AUXILIARY
        logical :: DIAGNOSTIC
        character(len=20) :: MESSAGE
    end type AUXILIARY

    type NUMERIC_SEQ
        sequence
        integer :: INT_VAL
        real :: REAL_VAL
        logical :: LOG_VAL
    end type NUMERIC_SEQ

    type :: POINT
        real :: X, Y
    contains
        procedure :: LENGTH
    end type POINT

contains
    real function LENGTH(this)
        class(POINT), intent(in) :: this
        LENGTH = sqrt(this%X**2 + this%Y**2)
    end function LENGTH
end module types

program testTypes
    use types
    implicit none

    type(person) :: p1
    type(kids) :: k1
    type(POINT) :: pt

    ! Test person type
    p1%forename = 'John Doe'
    p1%age = 30
    print *, 'Person forename:', trim(p1%forename)
    print *, 'Person age:', p1%age

    ! Test kids type
    k1%oldest_child%forename = 'Oldest Child'
    k1%oldest_child%age = 10
    print *, 'Oldest child forename:', trim(k1%oldest_child%forename)

    ! Test POINT type and its method
    pt%X = 3.0
    pt%Y = 4.0
    print *, 'Point length:', pt%LENGTH()

end program testTypes