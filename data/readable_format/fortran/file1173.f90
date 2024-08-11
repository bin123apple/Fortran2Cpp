module GribHandler
implicit none
contains
    subroutine grib_index_get_int(key, value)
        character(*), intent(in) :: key
        integer, intent(out) :: value
        ! Mock behavior: return a value based on the key
        if (key == "intKey") then
            value = 42
        else
            value = -1
        endif
    end subroutine grib_index_get_int

    subroutine grib_index_get_string(key, value)
        character(*), intent(in) :: key
        character(*), intent(out) :: value
        ! Mock behavior: return a string based on the key
        if (key == "stringKey") then
            value = "Hello"
        else
            value = "Unknown"
        endif
    end subroutine grib_index_get_string

    subroutine grib_index_select_int(key, value)
        character(*), intent(in) :: key
        integer, intent(in) :: value
        ! For testing: just print the selected key and value
        print *, "Selected", key, "with value", value
    end subroutine grib_index_select_int
end module GribHandler

program testGribHandler
    use GribHandler
    implicit none
    integer :: intValue
    character(20) :: stringValue

    call grib_index_get_int("intKey", intValue)
    print *, "Test grib_index_get_int:", intValue

    call grib_index_get_string("stringKey", stringValue)
    print *, "Test grib_index_get_string:", stringValue

    call grib_index_select_int("intKey", 42)
end program testGribHandler