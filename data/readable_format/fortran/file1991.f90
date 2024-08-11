module MPEProblem9
    implicit none
    private

    type, public :: TPEProblem9
    contains
        procedure, nopass :: present
    end type TPEProblem9

contains

    subroutine present
        write (*, '(A)') 'Problem 9. Special Pythagorean triplet.'
        write (*, '(A, I12)') 'Product 1: ', product1() ! Corrected format specifier
    end subroutine

    pure function product1() result(product)
        integer, parameter :: limit = 1000
        integer :: product
        integer :: a, b, c

        product = 0

        do c = 1, limit
            do b = 1, c - 1
                do a = 1, b - 1
                    if (a + b + c == limit) then
                        if (a**2 + b**2 == c**2) then
                            product = a * b * c
                            return
                        end if
                    end if
                end do
            end do
        end do
    end function product1

end module MPEProblem9

program TestMPEProblem9
    use MPEProblem9
    implicit none

    type(TPEProblem9) :: problem

    ! Invoke the present subroutine to display the result
    call problem%present()

end program TestMPEProblem9