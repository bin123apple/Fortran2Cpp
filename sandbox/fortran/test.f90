module mod21
    implicit none
contains
    subroutine test_mod21()
        print *, "mod21 is working"
    end subroutine test_mod21
end module mod21

module mod22
    implicit none
contains
    subroutine test_mod22()
        print *, "mod22 is working"
    end subroutine test_mod22
end module mod22

module mod23
    use mod22
    implicit none
contains
    subroutine test_mod23()
        print *, "mod23 is working"
        call test_mod22() ! Ensure mod22 is accessible
    end subroutine test_mod23
end module mod23

! Merge test functionality into a single program
program test_program
    use mod21
    use mod22
    use mod23
    implicit none
    
    ! Test modules here
    call test_mod21()
    call test_mod22()
    call test_mod23()
end program test_program