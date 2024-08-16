[INST] Translate this Fortran code to C++: 
program string_xor_program
    implicit none
    character(len=:), allocatable :: result

    ! Test cases
    result = string_xor("111000", "101010")
    if (result /= "010010") then
        write(*,*) "Assertion failed: string_xor('111000', '101010') /= '010010'"
        call exit(1)
    end if

    result = string_xor("1", "1")
    if (result /= "0") then
        write(*,*) "Assertion failed: string_xor('1', '1') /= '0'"
        call exit(1)
    end if

    result = string_xor("0101", "0000")
    if (result /= "0101") then
        write(*,*) "Assertion failed: string_xor('0101', '0000') /= '0101'"
        call exit(1)
    end if

contains

    function string_xor(a, b) result(output)
        character(len=*), intent(in) :: a, b
        character(len=:), allocatable :: output
        integer :: i, len_a, len_b, min_len

        len_a = len(a)
        len_b = len(b)
        min_len = min(len_a, len_b)
        output = ""

        do i = 1, min_len
            if (a(i:i) == b(i:i)) then
                output = output // '0'
            else
                output = output // '1'
            end if
        end do

        if (len_a > len_b) then
            output = output // a(min_len+1:len_a)
        else if (len_b > len_a) then
            output = output // b(min_len+1:len_b)
        end if
    end function string_xor

end program string_xor_program [/INST]

[INST] Translate this Fortran code to C++: 
program string_xor_program
    implicit none
    character(len=:), allocatable :: result

    ! Test cases
    result = string_xor("111000", "101010")
    if (result /= "010010") then
        write(*,*) "Assertion failed: string_xor('111000', '101010') /= '010010'"
        call exit(1)
    end if

    result = string_xor("1", "1")
    if (result /= "0") then
        write(*,*) "Assertion failed: string_xor('1', '1') /= '0'"
        call exit(1)
    end if

    result = string_xor("0101", "0000")
    if (result /= "0101") then
        write(*,*) "Assertion failed: string_xor('0101', '0000') /= '0101'"
        call exit(1)
    end if

contains

    function string_xor(a, b) result(output)
        character(len=*), intent(in) :: a, b
        character(len=:), allocatable :: output
        integer :: i, len_a, len_b, min_len

        len_a = len(a)
        len_b = len(b)
        min_len = min(len_a, len_b)
        output = ""

        do i = 1, min_len
            if (a(i:i) == b(i:i)) then
                output = output // '0'
            else
                output = output // '1'
            end if
        end do

        if (len_a > len_b) then
            output = output // a(min_len+1:len_a)
        else if (len_b > len_a) then
            output = output // b(min_len+1:len_b)
        end if
    end function string_xor

end program string_xor_program [/INST]

[INST] Translate this Fortran code to C++: 
program string_xor_program
    implicit none
    character(len=:), allocatable :: result

    ! Test cases
    result = string_xor("111000", "101010")
    if (result /= "010010") then
        write(*,*) "Assertion failed: string_xor('111000', '101010') /= '010010'"
        call exit(1)
    end if

    result = string_xor("1", "1")
    if (result /= "0") then
        write(*,*) "Assertion failed: string_xor('1', '1') /= '0'"
        call exit(1)
    end if

    result = string_xor("0101", "0000")
    if (result /= "0101") then
        write(*,*) "Assertion failed: string_xor('0101', '0000') /= '0101'"
        call exit(1)
    end if

contains

    function string_xor(a, b) result(output)
        character(len=*), intent(in) :: a, b
        character(len=:), allocatable :: output
        integer :: i, len_a, len_b, min_len

        len_a = len(a)
        len_b = len(b)
        min_len = min(len_a, len_b)
        output = ""

        do i = 1, min_len
            if (a(i:i) == b(i:i)) then
                output = output // '0'
            else
                output = output // '1'
            end if
        end do

        if (len_a > len_b) then
            output = output // a(min_len+1:len_a)
        else if (len_b > len_a) then
            output = output // b(min_len+1:len_b)
        end if
    end function string_xor

end program string_xor_program [/INST]

[INST] Translate this Fortran code to C++: 
program string_xor_program
    implicit none
    character(len=:), allocatable :: result

    ! Test cases
    result = string_xor("111000", "101010")
    if (result /= "010010") then
        write(*,*) "Assertion failed: string_xor('111000', '101010') /= '010010'"
        call exit(1)
    end if

    result = string_xor("1", "1")
    if (result /= "0") then
        write(*,*) "Assertion failed: string_xor('1', '1') /= '0'"
        call exit(1)
    end if

    result = string_xor("0101", "0000")
    if (result /= "0101") then
        write(*,*) "Assertion failed: string_xor('0101', '0000') /= '0101'"
        call exit(1)
    end if

contains

    function string_xor(a, b) result(output)
        character(len=*), intent(in) :: a, b
        character(len=:), allocatable :: output
        integer :: i, len_a, len_b, min_len

        len_a = len(a)
        len_b = len(b)
        min_len = min(len_a, len_b)
        output = ""

        do i = 1, min_len
            if (a(i:i) == b(i:i)) then
                output = output // '0'
            else
                output
