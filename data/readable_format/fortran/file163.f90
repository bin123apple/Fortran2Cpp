module m
    use iso_c_binding
    implicit none

    type, bind(C) :: info_t
        integer(c_int) :: type
    end type info_t

contains
    function liter_cb(link_info) result(res) bind(C)
        type(info_t), intent(in) :: link_info
        integer(c_int) :: res

        res = 0
    end function liter_cb
end module m

program test_liter_cb
    use m
    implicit none

    type(info_t) :: link_info
    integer(c_int) :: result

    link_info%type = 1  ! Example value
    result = liter_cb(link_info)

    print *, "Result of liter_cb:", result
end program test_liter_cb