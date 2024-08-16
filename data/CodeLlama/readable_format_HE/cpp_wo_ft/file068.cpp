[INST] Translate this Fortran code to C++: 
program decimal_to_binary_program
    implicit none
    call test_decimal_to_binary
    write(*,*) "All assertions passed."

contains

    character(len=100) function decimal_to_binary(decimal)
        implicit none
        integer, intent(in) :: decimal
        integer :: temp
        character(len=100) :: out
        character(len=1) :: digit

        out = ""
        if (decimal == 0) then
            decimal_to_binary = "db0db"
            return
        end if

        temp = decimal
        do while (temp > 0)
            write(digit, '(I1)') mod(temp, 2)
            out = trim(digit) // out
            temp = temp / 2
        end do

        decimal_to_binary = "db" // trim(out) // "db"
    end function decimal_to_binary

    subroutine test_decimal_to_binary
        implicit none
        character(len=100) :: result

        result = decimal_to_binary(0)
        if (trim(result) /= "db0db") then
            write(*,*) "Assertion failed: decimal_to_binary(0) == 'db0db'"
            call exit(1)
        end if

        result = decimal_to_binary(32)
        if (trim(result) /= "db100000db") then
            write(*,*) "Assertion failed: decimal_to_binary(32) == 'db100000db'"
            call exit(1)
        end if

        result = decimal_to_binary(103)
        if (trim(result) /= "db1100111db") then
            write(*,*) "Assertion failed: decimal_to_binary(103) == 'db1100111db'"
            call exit(1)
        end if

        result = decimal_to_binary(15)
        if (trim(result) /= "db1111db") then
            write(*,*) "Assertion failed: decimal_to_binary(15) == 'db1111db'"
            call exit(1)
        end if
    end subroutine test_decimal_to_binary

end program decimal_to_binary_program [/INST]

[INST] Translate this Fortran code to C++: 
program decimal_to_binary_program
    implicit none
    call test_decimal_to_binary
    write(*,*) "All assertions passed."

contains

    character(len=100) function decimal_to_binary(decimal)
        implicit none
        integer, intent(in) :: decimal
        integer :: temp
        character(len=100) :: out
        character(len=1) :: digit

        out = ""
        if (decimal == 0) then
            decimal_to_binary = "db0db"
            return
        end if

        temp = decimal
        do while (temp > 0)
            write(digit, '(I1)') mod(temp, 2)
            out = trim(digit) // out
            temp = temp / 2
        end do

        decimal_to_binary = "db" // trim(out) // "db"
    end function decimal_to_binary

    subroutine test_decimal_to_binary
        implicit none
        character(len=100) :: result

        result = decimal_to_binary(0)
        if (trim(result) /= "db0db") then
            write(*,*) "Assertion failed: decimal_to_binary(0) == 'db0db'"
            call exit(1)
        end if

        result = decimal_to_binary(32)
        if (trim(result) /= "db100000db") then
            write(*,*) "Assertion failed: decimal_to_binary(32) == 'db100000db'"
            call exit(1)
        end if

        result = decimal_to_binary(103)
        if (trim(result) /= "db1100111db") then
            write(*,*) "Assertion failed: decimal_to_binary(103) == 'db1100111db'"
            call exit(1)
        end if

        result = decimal_to_binary(15)
        if (trim(result) /= "db1111db") then
            write(*,*) "Assertion failed: decimal_to_binary(15) == 'db1111db'"
            call exit(1)
        end if
    end subroutine test_decimal_to_binary

end program decimal_to_binary_program [/INST]

[INST] Translate this Fortran code to C++: 
program decimal_to_binary_program
    implicit none
    call test_decimal_to_binary
    write(*,*) "All assertions passed."

contains

    character(len=100) function decimal_to_binary(decimal)
        implicit none
        integer, intent(in) :: decimal
        integer :: temp
        character(len=100) :: out
        character(len=1) :: digit

        out = ""
        if (decimal == 0) then
            decimal_to_binary = "db0db"
            return
        end if

        temp = decimal
        do while (temp > 0)
            write(digit, '(I1)') mod(temp, 2)
            out = trim(digit) // out
            temp = temp / 2
        end do

        decimal_to_binary = "db" // trim(out) // "db"
    end function decimal_to_binary

    subroutine test_decimal_to_binary
        implicit none
        character(len=100) :: result

        result = decimal_to_binary(0)
        if (trim(result) /= "db0db") then
            write(*,*) "Assertion failed: decimal_to_binary(0) == 'db0db'"
            call exit(1)
        end if

        result = decimal_to_binary(32)
        if (trim(result) /= "db100000db") then
            write(*,*) "Assertion failed: decimal_to_binary(32) == 'db100000db'"
            call exit(1)
        end if

        result = decimal_to_binary(103)
        if (trim(result) /= "db1100111db") then
            write(*,*) "Assertion failed: decimal_to_binary(103) == 'db1100111db'"
            call exit(1)
        end if

        result = decimal_to_binary(15)
        if (trim(result) /= "db1111db") then
            write(*,*) "Assertion failed: decimal_to_binary(15) == 'db1111db'"
            call exit(1)
        end if
    end subroutine test_decimal_to_binary

end program decimal_to_binary_program [/INST]

[INST] Translate this Fortran code to C++: 
program decimal_to_binary_program
    implicit none
    call test_decimal_to_binary
    write(*,*) "All assertions passed."

contains

    character(len=100) function decimal_to_binary(decimal)
        implicit none
        integer, intent(in) :: decimal
        integer :: temp
        character(len=100) :: out
        character(len=1) :: digit

        out = ""
        if (decimal == 0) then
            decimal_to_binary = "db0db"
            return
        end if

        temp = decimal
        do while (temp > 0)
            write(digit, '(I1)') mod(temp, 2)
            out = trim(digit) // out
            temp = temp / 2
        end do

        decimal_to_binary = "db" // trim(out) // "db"
    end function decimal_to_binary

    subroutine test_decimal_to_binary
        implicit none
