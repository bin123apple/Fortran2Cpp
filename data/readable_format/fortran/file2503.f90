program boz_test
    implicit none

    integer(1), parameter :: b1 = b'000000000001111'
    integer(2), parameter :: b2 = b'00000000000000000111000011110000'
    integer(4), parameter :: &
    &  b4 = b'0000000000000000000000000000000001110000111100001111000011110000'

    integer(1), parameter :: o1 = o'0012'
    integer(2), parameter :: o2 = o'0004321'
    integer(4), parameter :: o4 = o'0000000043210765'

    integer(1), parameter :: z1 = z'0a'
    integer(2), parameter :: z2 = z'00ab'
    integer(4), parameter :: z4 = z'0000dead'

    call assert_equal(int(b1, kind=4), 15, "b1")
    call assert_equal(int(b2, kind=4), 28912, "b2")
    call assert_equal(b4, 1894838512, "b4")

    call assert_equal(int(o1, kind=4), 10, "o1")
    call assert_equal(int(o2, kind=4), 2257, "o2")
    call assert_equal(o4, 9245173, "o4")

    call assert_equal(int(z1, kind=4), 10, "z1")
    call assert_equal(int(z2, kind=4), 171, "z2")
    call assert_equal(z4, 57005, "z4")

contains
    subroutine assert_equal(actual, expected, name)
        integer, intent(in) :: actual
        integer, intent(in) :: expected
        character(len=*), intent(in) :: name

        if (actual /= expected) then
            print *, "Test failed: ", name, " expected: ", expected, " but got: ", actual
            call abort
        else
            print *, "Test passed: ", name
        end if
    end subroutine assert_equal

end program boz_test