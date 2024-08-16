[INST] Translate this Fortran code to C++: 
program change_base_program
    implicit none
    character(len=100) :: result
    integer :: x

    ! Assertions
    if (trim(change_base(8, 3)) /= "22") then
        write(*,*) "Assertion failed: change_base(8, 3) == '22'"
        call exit(1)
    end if
    if (trim(change_base(9, 3)) /= "100") then
        write(*,*) "Assertion failed: change_base(9, 3) == '100'"
        call exit(1)
    end if
    if (trim(change_base(234, 2)) /= "11101010") then
        write(*,*) "Assertion failed: change_base(234, 2) == '11101010'"
        call exit(1)
    end if
    if (trim(change_base(16, 2)) /= "10000") then
        write(*,*) "Assertion failed: change_base(16, 2) == '10000'"
        call exit(1)
    end if
    if (trim(change_base(8, 2)) /= "1000") then
        write(*,*) "Assertion failed: change_base(8, 2) == '1000'"
        call exit(1)
    end if
    if (trim(change_base(7, 2)) /= "111") then
        write(*,*) "Assertion failed: change_base(7, 2) == '111'"
        call exit(1)
    end if

    do x = 2, 7
        if (trim(change_base(x, x + 1)) /= trim(adjustl(itoa(x)))) then
            write(*,*) "Assertion failed: change_base(", x, ", ", x + 1, ") == ", x
            call exit(1)
        end if
    end do

contains
    ! Function to change base
    character(len=100) function change_base(x, base)
        implicit none
        integer, intent(in) :: x, base
        integer :: temp_x, remainder
        character(len=100) :: out, temp_str
        out = ""
        temp_x = x
        do while (temp_x > 0)
            remainder = mod(temp_x, base)
            write(temp_str, '(I0)') remainder
            out = trim(adjustl(temp_str)) // out
            temp_x = temp_x / base
        end do
        change_base = out
    end function change_base

    ! Integer to string conversion function
    character(len=100) function itoa(num)
        implicit none
        integer, intent(in) :: num
        write(itoa, '(I0)') num
    end function itoa

end program change_base_program [/INST]

[INST] Translate this Fortran code to C++: 
program change_base_program
    implicit none
    character(len=100) :: result
    integer :: x

    ! Assertions
    if (trim(change_base(8, 3)) /= "22") then
        write(*,*) "Assertion failed: change_base(8, 3) == '22'"
        call exit(1)
    end if
    if (trim(change_base(9, 3)) /= "100") then
        write(*,*) "Assertion failed: change_base(9, 3) == '100'"
        call exit(1)
    end if
    if (trim(change_base(234, 2)) /= "11101010") then
        write(*,*) "Assertion failed: change_base(234, 2) == '11101010'"
        call exit(1)
    end if
    if (trim(change_base(16, 2)) /= "10000") then
        write(*,*) "Assertion failed: change_base(16, 2) == '10000'"
        call exit(1)
    end if
    if (trim(change_base(8, 2)) /= "1000") then
        write(*,*) "Assertion failed: change_base(8, 2) == '1000'"
        call exit(1)
    end if
    if (trim(change_base(7, 2)) /= "111") then
        write(*,*) "Assertion failed: change_base(7, 2) == '111'"
        call exit(1)
    end if

    do x = 2, 7
        if (trim(change_base(x, x + 1)) /= trim(adjustl(itoa(x)))) then
            write(*,*) "Assertion failed: change_base(", x, ", ", x + 1, ") == ", x
            call exit(1)
        end if
    end do

contains
    ! Function to change base
    character(len=100) function change_base(x, base)
        implicit none
        integer, intent(in) :: x, base
        integer :: temp_x, remainder
        character(len=100) :: out, temp_str
        out = ""
        temp_x = x
        do while (temp_x > 0)
            remainder = mod(temp_x, base)
            write(temp_str, '(I0)') remainder
            out = trim(adjustl(temp_str)) // out
            temp_x = temp_x / base
        end do
        change_base = out
    end function change_base

    ! Integer to string conversion function
    character(len=100) function itoa(num)
        implicit none
        integer, intent(in) :: num
        write(itoa, '(I0)') num
    end function itoa

end program change_base_program [/INST]

[INST] Translate this Fortran code to C++: 
program change_base_program
    implicit none
    character(len=100) :: result
    integer :: x

    ! Assertions
    if (trim(change_base(8, 3)) /= "22") then
        write(*,*) "Assertion failed: change_base(8, 3) == '22'"
        call exit(1)
    end if
    if (trim(change_base(9, 3)) /= "100") then
        write(*,*) "Assertion failed: change_base(9, 3) == '100'"
        call exit(1)
    end if
    if (trim(change_base(234, 2)) /= "11101010") then
        write(*,*) "Assertion failed: change_base(234, 2) == '11101010'"
        call exit(1)
    end if
    if (trim(change_base(16, 2)) /= "10000") then
        write(*,*) "Assertion failed: change_base(16, 2) == '10000'"
        call exit(1)
    end if
    if (trim(change_base(8, 2)) /= "1000") then
        write(*,*) "Assertion failed: change_base(8, 2) == '1000'"
        call exit(1)
    end if
    if (trim(change_base(7, 2)) /= "111") then
        write(*,*) "Assertion failed: change_base(7, 2) == '111'"
        call exit(1)
    end if

    do x = 2, 7
        if (trim(change_base(x, x + 1)) /= trim(adjustl(itoa(x)))) then
            write(*,*) "Assertion failed: change_base(", x, ", ", x + 1, ") == ", x
            call exit(1)
        end if
    end do

contains
    ! Function to change base
    character(len=100) function change_base(x,
