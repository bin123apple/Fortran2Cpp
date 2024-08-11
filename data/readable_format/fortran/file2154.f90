module test_types
    implicit none

    type :: Test
        integer :: i
    end type Test

end module test_types

program testProgram
    use test_types
    implicit none

    type :: TestReference
        class(Test), allocatable :: testObj
    end type TestReference

    type(TestReference) :: testList
    class(Test), allocatable :: x
    logical :: test_passed

    test_passed = .true.

    ! Initialize testList with a Test object
    allocate(testList%testObj, source=Test(99))

    ! Directly access the test object's value without using a pointer
    x = testList%testObj

    ! Use the SELECT TYPE construct to verify the translation
    select type (y => testList%testObj)
        type is (Test)
            if (x%i .ne. y%i) then
                print *, 'Test failed: x%i /= y%i'
                test_passed = .false.
            end if
        class default
            print *, 'Test failed: Type mismatch'
            test_passed = .false.
    end select

    if (test_passed) then
        print *, 'Fortran Test Passed!'
    else
        print *, 'Fortran Test Failed!'
    end if

end program testProgram