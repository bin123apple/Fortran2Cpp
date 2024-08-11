program test
    implicit none
    integer :: i, j
    integer, parameter :: a(4,4,4) = reshape([ (i,i=1,64) ], [4,4,4])
    integer, parameter :: v(4) = [4, 1, 3, 2]
    integer :: b1(3,3) = a(1:3, 2, 2:4)
    integer :: b2(1,3) = a(2:2, 4, [1,4,3])
    integer :: b2b(3) = a([1,4,3], 2, 4)
    integer :: b3(4) = a(1, v, 3)
    integer :: b4(3,3) = a(v([2,4,3]), 2, [2,3,4])
    integer, parameter :: expectedB1(3,3) = reshape([21,22,23, 37,38,39, 53,54,55], [3,3])
    integer, parameter :: expectedB2(1,3) = reshape([14, 62, 46], [1,3])
    integer, parameter :: expectedB2b(3) = [53, 56, 55]
    integer, parameter :: expectedB3(4) = [45, 33, 41, 37]
    integer, parameter :: expectedB4(3,3) = reshape([21,22,23, 37,38,39, 53,54,55], [3,3])

    ! Running tests
    call testArray2D("b1", b1, expectedB1)
    call testArray2D("b2", b2, expectedB2)
    call testArray1D("b2b", b2b, expectedB2b)
    call testArray1D("b3", b3, expectedB3)
    call testArray2D("b4", b4, expectedB4)

contains

    subroutine testArray1D(name, array, expected)
        character(len=*), intent(in) :: name
        integer, intent(in) :: array(:), expected(:)
        if (all(array == expected)) then
            write(*,*) trim(name) // " passed."
        else
            write(*,*) trim(name) // " failed."
            call abort()
        end if
    end subroutine testArray1D

    subroutine testArray2D(name, array, expected)
        character(len=*), intent(in) :: name
        integer, intent(in) :: array(:,:), expected(:,:)
        if (all(array == expected)) then
            write(*,*) trim(name) // " passed."
        else
            write(*,*) trim(name) // " failed."
            call abort()
        end if
    end subroutine testArray2D

end program test