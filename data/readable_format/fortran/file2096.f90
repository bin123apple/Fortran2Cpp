module x
    use iso_c_binding
contains
    subroutine glutInit_f03()
        type(c_ptr), dimension(1), target :: argv=C_NULL_PTR
        character(c_char), dimension(10), target :: empty_string=C_NULL_CHAR
        argv(1)=C_LOC(empty_string)
    end subroutine glutInit_f03
end module x

program main
    use x
    call glutInit_f03()
    print *, "GLUT Initialized successfully."
end program main