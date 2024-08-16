[INST] Translate this Fortran code to C++: 
program fib5_program
    implicit none

    ! Assertions
    if (fib5(5) /= 4) then
        write(*,*) "fib5(5) == 4: assertion failed"
        call exit(1)
    end if

    if (fib5(8) /= 28) then
        write(*,*) "fib5(8) == 28: assertion failed"
        call exit(1)
    end if

    if (fib5(10) /= 104) then
        write(*,*) "fib5(10) == 104: assertion failed"
        call exit(1)
    end if

    if (fib5(12) /= 386) then
        write(*,*) "fib5(12) == 386: assertion failed"
        call exit(1)
    end if

contains

    ! Function definition
    integer function fib5(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do

        fib5 = f(n)
    end function fib5

end program fib5_program [/INST]

[INST] Translate this Fortran code to C++: 
program fib6_program
    implicit none

    ! Assertions
    if (fib6(5) /= 4) then
        write(*,*) "fib6(5) == 4: assertion failed"
        call exit(1)
    end if

    if (fib6(8) /= 28) then
        write(*,*) "fib6(8) == 28: assertion failed"
        call exit(1)
    end if

    if (fib6(10) /= 104) then
        write(*,*) "fib6(10) == 104: assertion failed"
        call exit(1)
    end if

    if (fib6(12) /= 386) then
        write(*,*) "fib6(12) == 386: assertion failed"
        call exit(1)
    end if

contains

    ! Function definition
    integer function fib6(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do

        fib6 = f(n)
    end function fib6

end program fib6_program [/INST]

[INST] Translate this Fortran code to C++: 
program fib7_program
    implicit none

    ! Assertions
    if (fib7(5) /= 4) then
        write(*,*) "fib7(5) == 4: assertion failed"
        call exit(1)
    end if

    if (fib7(8) /= 28) then
        write(*,*) "fib7(8) == 28: assertion failed"
        call exit(1)
    end if

    if (fib7(10) /= 104) then
        write(*,*) "fib7(10) == 104: assertion failed"
        call exit(1)
    end if

    if (fib7(12) /= 386) then
        write(*,*) "fib7(12) == 386: assertion failed"
        call exit(1)
    end if

contains

    ! Function definition
    integer function fib7(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do

        fib7 = f(n)
    end function fib7

end program fib7_program [/INST]

[INST] Translate this Fortran code to C++: 
program fib8_program
    implicit none

    ! Assertions
    if (fib8(5) /= 4) then
        write(*,*) "fib8(5) == 4: assertion failed"
        call exit(1)
    end if

    if (fib8(8) /= 28) then
        write(*,*) "fib8(8) == 28: assertion failed"
        call exit(1)
    end if

    if (fib8(10) /= 104) then
        write(*,*) "fib8(10) == 104: assertion failed"
        call exit(1)
    end if

    if (fib8(12) /= 386) then
        write(*,*) "fib8(12) == 386: assertion failed"
        call exit(1)
    end if

contains

    ! Function definition
    integer function fib8(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do

        fib8 = f(n)
    end function fib8

end program fib8_program [/INST]

[INST] Translate this Fortran code to C++: 
program fib9_program
    implicit none

    ! Assertions
    if (fib9(5) /= 4) then
        write(*,*) "fib9(5) == 4: assertion failed"
        call exit(1)
    end if

    if (fib9(8) /= 28) then
        write(*,*) "fib9(8) == 28: assertion failed"
        call exit(1)
    end if

    if (fib9(10) /= 104) then
        write(*,*) "fib9(10) == 104: assertion failed"
        call exit(1)
    end if

    if (fib9(12) /= 386) then
        write(*,*) "fib9(12) == 386: assertion failed"
        call exit(1)
    end if

contains

    ! Function definition
    integer function fib9(n)
        implicit none
        integer, intent(in) :: n
        integer, dimension(0:99) :: f
        integer :: i

        ! Initialize the first four elements
        f(0) = 0
        f(1) = 0
        f(2) = 2
        f(3) = 0

        ! Compute the sequence
        do i = 4, n
            f(i) = f(i-1) + f(i-2) + f(i-3) + f(i-4)
        end do
