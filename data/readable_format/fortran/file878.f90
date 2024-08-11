module original_module
    implicit none
    integer, target :: t1
    integer, pointer :: p1
    integer, target :: i0 = 2
    integer, target, dimension(3) :: vec = (/1, 1, 1/)
    type :: t
        integer, pointer :: dpc
        integer :: i = 0
    end type t
    type(t), save, target :: u
    integer, pointer :: dp
    integer, pointer :: dp2
    integer, pointer :: dp3
contains
    subroutine init
        p1 => t1
        u%dpc => i0
        dp => i0
        dp2 => vec(2)
        dp3 => u%i
    end subroutine init
end module original_module

program testFortranFunctionality
    use original_module
    implicit none
    
    call init
    
    ! Test setup
    t1 = 10
    p1 = 20
    
    ! Test 1: Check pointer assignment to a variable
    if (t1 /= 20) then
        print *, "Test 1 Failed"
    else
        print *, "Test 1 Passed"
    end if
    
    ! Assigning values through pointers
    dp = 5
    if (i0 /= 5) then
        print *, "Pointer dp Test Failed"
    else
        print *, "Pointer dp Test Passed"
    end if
    
    u%dpc = 6
    if (i0 /= 6) then
        print *, "Pointer u%dpc Test Failed"
    else
        print *, "Pointer u%dpc Test Passed"
    end if
    
    dp2 = 3
    if (vec(2) /= 3) then
        print *, "Pointer dp2 Test Failed"
    else
        print *, "Pointer dp2 Test Passed"
    end if
    
    dp3 = 4
    if (u%i /= 4) then
        print *, "Pointer dp3 Test Failed"
    else
        print *, "Pointer dp3 Test Passed"
    end if
end program testFortranFunctionality