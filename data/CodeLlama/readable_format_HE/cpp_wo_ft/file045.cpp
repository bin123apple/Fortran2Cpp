[INST] Translate this Fortran code to C++: 
program main
    implicit none
    integer :: i, x, y
    real :: rand_val

    ! Assertions
    if (add(0, 1) /= 1) then
        write(*,*) "Assertion failed: add(0, 1) == 1"
        call exit(1)
    end if

    if (add(1, 0) /= 1) then
        write(*,*) "Assertion failed: add(1, 0) == 1"
        call exit(1)
    end if

    if (add(2, 3) /= 5) then
        write(*,*) "Assertion failed: add(2, 3) == 5"
        call exit(1)
    end if

    if (add(5, 7) /= 12) then
        write(*,*) "Assertion failed: add(5, 7) == 12"
        call exit(1)
    end if

    if (add(7, 5) /= 12) then
        write(*,*) "Assertion failed: add(7, 5) == 12"
        call exit(1)
    end if

    ! Loop with random number generation and assertions
    do i = 1, 100
        call random_number(rand_val)
        x = int(rand_val * 1000)
        call random_number(rand_val)
        y = int(rand_val * 1000)
        if (add(x, y) /= x + y) then
            write(*,*) "Assertion failed: add(", x, ", ", y, ") == ", x + y
            call exit(1)
        end if
    end do

contains

    integer function add(x, y)
        integer, intent(in) :: x, y
        add = x + y
    end function add

end program main [/INST]

[INST] Translate this Fortran code to C++: 
program main
    implicit none
    integer :: i, x, y
    real :: rand_val

    ! Assertions
    if (add(0, 1) /= 1) then
        write(*,*) "Assertion failed: add(0, 1) == 1"
        call exit(1)
    end if

    if (add(1, 0) /= 1) then
        write(*,*) "Assertion failed: add(1, 0) == 1"
        call exit(1)
    end if

    if (add(2, 3) /= 5) then
        write(*,*) "Assertion failed: add(2, 3) == 5"
        call exit(1)
    end if

    if (add(5, 7) /= 12) then
        write(*,*) "Assertion failed: add(5, 7) == 12"
        call exit(1)
    end if

    if (add(7, 5) /= 12) then
        write(*,*) "Assertion failed: add(7, 5) == 12"
        call exit(1)
    end if

    ! Loop with random number generation and assertions
    do i = 1, 100
        call random_number(rand_val)
        x = int(rand_val * 1000)
        call random_number(rand_val)
        y = int(rand_val * 1000)
        if (add(x, y) /= x + y) then
            write(*,*) "Assertion failed: add(", x, ", ", y, ") == ", x + y
            call exit(1)
        end if
    end do

contains

    integer function add(x, y)
        integer, intent(in) :: x, y
        add = x + y
    end function add

end program main [/INST]

[INST] Translate this Fortran code to C++: 
program main
    implicit none
    integer :: i, x, y
    real :: rand_val

    ! Assertions
    if (add(0, 1) /= 1) then
        write(*,*) "Assertion failed: add(0, 1) == 1"
        call exit(1)
    end if

    if (add(1, 0) /= 1) then
        write(*,*) "Assertion failed: add(1, 0) == 1"
        call exit(1)
    end if

    if (add(2, 3) /= 5) then
        write(*,*) "Assertion failed: add(2, 3) == 5"
        call exit(1)
    end if

    if (add(5, 7) /= 12) then
        write(*,*) "Assertion failed: add(5, 7) == 12"
        call exit(1)
    end if

    if (add(7, 5) /= 12) then
        write(*,*) "Assertion failed: add(7, 5) == 12"
        call exit(1)
    end if

    ! Loop with random number generation and assertions
    do i = 1, 100
        call random_number(rand_val)
        x = int(rand_val * 1000)
        call random_number(rand_val)
        y = int(rand_val * 1000)
        if (add(x, y) /= x + y) then
            write(*,*) "Assertion failed: add(", x, ", ", y, ") == ", x + y
            call exit(1)
        end if
    end do

contains

    integer function add(x, y)
        integer, intent(in) :: x, y
        add = x + y
    end function add

end program main [/INST]

[INST] Translate this Fortran code to C++: 
program main
    implicit none
    integer :: i, x, y
    real :: rand_val

    ! Assertions
    if (add(0, 1) /= 1) then
        write(*,*) "Assertion failed: add(0, 1) == 1"
        call exit(1)
    end if

    if (add(1, 0) /= 1) then
        write(*,*) "Assertion failed: add(1, 0) == 1"
        call exit(1)
    end if

    if (add(2, 3) /= 5) then
        write(*,*) "Assertion failed: add(2, 3) == 5"
        call exit(1)
    end if

    if (add(5, 7) /= 12) then
        write(*,*) "Assertion failed: add(5, 7) == 12"
        call exit(1)
    end if

    if (add(7, 5) /= 12) then
        write(*,*) "Assertion failed: add(7, 5) == 12"
        call exit(1)
    end if

    ! Loop with random number generation and assertions
    do i = 1, 100
        call random_number(rand_val)
        x = int(rand_val * 1000)
        call random_number(rand_val)
        y = int(rand_val * 1000)
        if (add(x, y) /= x + y) then
            write(*,*) "Assertion failed: add(", x, ", ", y, ") == ", x + y
            call exit(1)
        end if
    end do

contains

    integer function add(x, y)
        integer, intent(in) :: x, y
        add = x + y
    end function add

end program main [/INST]

[INST] Translate this Fortran code to C++: 
program main
    implicit none
    integer :: i, x, y
    real :: rand_val

    ! Assertions
    if (add(0, 1) /= 1) then
        write(*,*) "Assertion failed: add(0, 1) == 1"
        call exit(1)
    end if

    if (add(1, 0) /
