program test_s1
    implicit none

    type s1
        sequence
        real :: a
    end type s1

    type(s1) :: myStruct

    ! Initialize myStruct
    myStruct%a = 2.0

    ! Test
    call test_myStruct(myStruct)

contains

    subroutine test_myStruct(s)
        type(s1), intent(in) :: s
        real :: expected_value

        expected_value = 2.0

        if (s%a == expected_value) then
            print *, "Test passed, a = ", s%a
        else
            print *, "Test failed"
        endif
    end subroutine test_myStruct

end program test_s1