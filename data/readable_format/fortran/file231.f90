program test_array
    implicit none
    character(len=128) :: arr(2)

    ! Initialize array elements
    arr(1) = "abc"
    arr(2) = "foobar"

    call test_arr_values(arr)

contains

    subroutine test_arr_values(arr)
        character(len=128), intent(in) :: arr(2)
        
        if (trim(arr(1)) == "abc" .and. trim(arr(2)) == "foobar") then
            print *, "Test Passed!"
        else
            print *, "Test Failed!"
        endif
    end subroutine test_arr_values

end program test_array