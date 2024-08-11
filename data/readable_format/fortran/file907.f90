module ObjectsModule
    implicit none

    type, public :: TObjectList
        integer, allocatable :: intList(:)
        double precision, allocatable :: doubleList(:)
    contains
        procedure :: Add1
        procedure :: Add2
        procedure :: CheckIntElement
        procedure :: CheckDoubleElement
        generic :: Add => Add1, Add2
    end type TObjectList

contains

    subroutine Add1(self, item)
        class(TObjectList), intent(inout) :: self
        integer, intent(in) :: item
        if (.not. allocated(self%intList)) then
            allocate(self%intList(1))
            self%intList(1) = item
        else
            self%intList = [self%intList, item]
        endif
    end subroutine Add1

    subroutine Add2(self, item)
        class(TObjectList), intent(inout) :: self
        double precision, intent(in) :: item
        if (.not. allocated(self%doubleList)) then
            allocate(self%doubleList(1))
            self%doubleList(1) = item
        else
            self%doubleList = [self%doubleList, item]
        endif
    end subroutine Add2

    subroutine CheckIntElement(self, index, expected)
        class(TObjectList), intent(in) :: self
        integer, intent(in) :: index, expected
        if (self%intList(index) /= expected) then
            print *, "Test failed for integer list at index", index
            stop
        endif
    end subroutine CheckIntElement

    subroutine CheckDoubleElement(self, index, expected)
        class(TObjectList), intent(in) :: self
        integer, intent(in) :: index
        double precision, intent(in) :: expected
        if (abs(self%doubleList(index) - expected) > 1e-9) then
            print *, "Test failed for double list at index", index
            stop
        endif
    end subroutine CheckDoubleElement

end module ObjectsModule

program testObjects
    use ObjectsModule
    implicit none
    type(TObjectList) :: list

    ! Test adding an integer
    call list%Add(1)  ! Add1 is called
    call list%CheckIntElement(1, 1)

    ! Test adding a double
    call list%Add(2.0d0)  ! Add2 is called
    call list%CheckDoubleElement(1, 2.0d0)

    print *, "All Fortran tests passed."
end program testObjects