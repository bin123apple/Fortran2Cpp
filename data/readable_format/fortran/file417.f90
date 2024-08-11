program test
    implicit none
    integer, pointer :: p => null()
    call allocate_and_set(p, 5)
    print *, "Value pointed by p:", p
    deallocate(p)
contains
    subroutine allocate_and_set(ptr, value)
        integer, pointer :: ptr
        integer :: value
        allocate(ptr)
        ptr = value
    end subroutine allocate_and_set
end program test