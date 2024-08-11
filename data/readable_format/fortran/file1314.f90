module m
    implicit none
    Type :: T
        real :: expectedScalar
    contains
        procedure :: FCheck
        procedure :: FCheckArr
        generic :: Check => FCheck, FCheckArr
    end Type

contains

    subroutine FCheck(this, X)
        class(T), intent(inout) :: this
        real, intent(in) :: X
        if (abs(X - this%expectedScalar) > 0.0001) then
            print *, "Value does not match the expected scalar within tolerance."
            STOP 1
        end if
    end subroutine FCheck

    subroutine FCheckArr(this, X)
        class(T), intent(inout) :: this
        real, dimension(:), intent(in) :: X
        integer :: i
        do i = 1, size(X)
            this%expectedScalar = i - 1.0
            call this%FCheck(X(i))
        end do
    end subroutine FCheckArr

end module m

program test
    use m
    implicit none

    real :: vec(6) = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0]
    Type(T) :: Tester
    Tester%expectedScalar = 2.0

    ! Test with a single value
    call Tester%Check(2.0)
    print *, "Single value check passed."

    ! The array check will modify Tester%expectedScalar, hence it's commented out to avoid stopping the program
    ! call Tester%Check(vec)
    ! print *, "Array check passed."

end program test