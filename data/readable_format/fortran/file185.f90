program test_program
    implicit none

    type :: person
        character(len=20) :: forename
        integer :: age
    end type person

    enum, bind(c)
        enumerator :: red = 4, blue = 9
        enumerator :: yellow
    end enum

    type(person) :: p
    real*8, dimension(4) :: matrix, result
    integer :: key, n

    ! Test person type
    p%forename = 'John'
    p%age = 30
    print *, 'Person Name: ', p%forename
    print *, 'Person Age: ', p%age

    ! Test enum values
    print *, 'Color Red: ', red
    print *, 'Color Blue: ', blue
    print *, 'Color Yellow: ', yellow

    ! Test solve function
    n = 4
    matrix = (/1.0, 2.0, 3.0, 4.0/)
    key = 1
    result = solve(n, matrix, key)
    print *, 'Solve result: ', result

contains

    function solve(n, pmatrix, key) result(res)
        integer, intent(in) :: n, key
        real*8, dimension(n), intent(in) :: pmatrix
        real*8, dimension(n) :: res

        ! Dummy implementation, for demonstration
        res = pmatrix * key
    end function solve

end program test_program