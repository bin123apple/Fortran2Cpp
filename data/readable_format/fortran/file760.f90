program pointers_with_tests

    implicit none

    type :: two
        integer, allocatable :: ivla1 (:)
        integer, allocatable :: ivla2 (:, :)
    end type two

    logical, target :: logv
    complex, target :: comv
    character, target :: charv
    character (len=3), target :: chara
    integer, target :: intv
    integer, target, dimension (10,2) :: inta
    real, target :: realv
    type(two), target :: twov

    logical, pointer :: logp
    complex, pointer :: comp
    character, pointer :: charp
    character (len=3), pointer :: charap
    integer, pointer :: intp
    integer, pointer, dimension (:,:) :: intap
    real, pointer :: realp
    type(two), pointer :: twop

    ! Initialize original program functionality
    call initialize_program

    ! Run tests
    call run_tests

contains

    subroutine initialize_program
        nullify (logp)
        nullify (comp)
        nullify (charp)
        nullify (charap)
        nullify (intp)
        nullify (intap)
        nullify (realp)
        nullify (twop)

        logp => logv
        comp => comv
        charp => charv
        charap => chara
        intp => intv
        intap => inta
        realp => realv
        twop => twov

        logv = .true.
        comv = (1.0, 2.0)
        charv = 'a'
        chara = "abc"
        intv = 10
        inta = 1
        inta(3,1) = 3
        realv = 3.14

        allocate (twov%ivla1(3))
        allocate (twov%ivla2(2,2))
        twov%ivla1 = (/11, 12, 13/)
        twov%ivla2 = reshape((/211, 221, 212, 222/), shape(twov%ivla2))

        intv = intv + 1
    end subroutine initialize_program

    subroutine run_tests
        ! Test 1: Check if intv was incremented correctly
        if (intv == 11) then
            print *, "Test 1 Passed: intv incremented correctly."
        else
            print *, "Test 1 Failed: intv not incremented correctly."
        endif

        ! Test 2: Verify dynamic memory allocation and values in twov
        if (allocated(twov%ivla1) .and. all(twov%ivla1 == (/11, 12, 13/)) .and. &
            allocated(twov%ivla2) .and. all(twov%ivla2 == reshape((/211, 221, 212, 222/), shape(twov%ivla2)))) then
            print *, "Test 2 Passed: Dynamic arrays in twov allocated and assigned correctly."
        else
            print *, "Test 2 Failed: Error in dynamic arrays of twov."
        endif

        ! Additional tests can be added here
    end subroutine run_tests

end program pointers_with_tests