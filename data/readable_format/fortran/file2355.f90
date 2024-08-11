module CRASH_ModCaltz
contains
    function get_value() result(val)
        integer :: val
        val = 42
    end function get_value
end module CRASH_ModCaltz

program testCRASH_ModCaltz
    use CRASH_ModCaltz
    implicit none
    
    integer :: value
    
    value = get_value()
    print *, 'Value from CRASH_ModCaltz:', value
end program testCRASH_ModCaltz