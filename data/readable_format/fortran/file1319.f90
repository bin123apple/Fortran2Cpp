program test_dim
    implicit none
    integer(kind=8) :: result

    ! Test 1: p1 > p2
    result = specific__dim_i8(10_8, 5_8)
    call assert(result, 5_8, "Test 1")

    ! Test 2: p1 < p2
    result = specific__dim_i8(2_8, 3_8)
    call assert(result, 0_8, "Test 2")

    ! Test 3: p1 == p2
    result = specific__dim_i8(7_8, 7_8)
    call assert(result, 0_8, "Test 3")

contains

    elemental function specific__dim_i8(p1, p2) result(out)
        integer(kind=8), intent(in) :: p1, p2
        integer(kind=8) :: out
        out = dim(p1, p2)
    end function specific__dim_i8

    subroutine assert(value, expected, test_name)
        integer(kind=8), intent(in) :: value, expected
        character(len=*), intent(in) :: test_name
        if (value == expected) then
            print *, test_name, ": PASS"
        else
            print *, test_name, ": FAIL", "Expected", expected, "Got", value
        endif
    end subroutine assert

end program test_dim