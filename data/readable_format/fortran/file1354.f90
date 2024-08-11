module char_operations
  implicit none
  contains
    subroutine sfoo(ch1, ch2)
        character(len=*), intent(in) :: ch1, ch2
        if (ch1 /= ch2) call abort()
    end subroutine sfoo

    subroutine afoo(ch1, ch2)
        character(len=5), dimension(:), intent(in) :: ch1, ch2
        if (any(ch1 /= ch2)) call abort()
    end subroutine afoo

    function pfoo(ch2) result(ptr)
        character(len=5), dimension(:), target :: ch2
        character(len=5), dimension(:), pointer :: ptr
        ptr => ch2
    end function pfoo
end module char_operations

program test_char_initialiser
  use char_operations
  implicit none
  character(len=5), dimension(3) :: x
  character(len=5), dimension(:), pointer :: y
  x = [character(len=5) :: "is Ja", "ne Fo", "nda  "]

  ! Test sfoo
  call sfoo("is Ja", x(1))
  call sfoo("ne Fo", "ne Fo")
  
  ! Test afoo with expected success
  call afoo(["is Ja","ne Fo","nda  "], x)

  ! Test pfoo
  y => pfoo(["is Ja","ne Fo","nda  "])
  call afoo(y, ["is Ja","ne Fo","nda  "])
  
  ! If we reach this point, tests passed
  write(*,*) "All Fortran tests passed successfully."
end program test_char_initialiser