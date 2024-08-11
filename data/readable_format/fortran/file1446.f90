program test_c_interface
    use, intrinsic :: iso_c_binding
    implicit none
    character(kind=c_char, len=256), target :: arg = "Hello from Fortran" // c_null_char
    type(c_ptr) :: c
    integer :: i

    ! Demonstrating interfacing with C by using c_loc
    c = c_loc(arg)

    ! Simulating printing the string as if a C function were doing it
    ! This loop mimics what a function in C would do to print a C string
    do i = 1, len_trim(arg)
        write(*, "(A)", advance="no"), arg(i:i)
    end do
    write(*,*) ! Newline after printing the string

end program test_c_interface