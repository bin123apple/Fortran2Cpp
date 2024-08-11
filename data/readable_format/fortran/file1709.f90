module global
  public :: p, line
  interface p
    module procedure p
  end interface
  character(128) :: line = 'abcdefghijklmnopqrstuvwxyz'
contains
  subroutine p()
    character(128) :: word
    word = line
    call redirect_((/word/))
  end subroutine
  subroutine redirect_ (ch)
    character(*) :: ch(:)
    if (ch(1) /= line) call abort ()
  end subroutine redirect_
end module global

module my_module
  implicit none
  type point
    real :: x
  end type point
  type(point), pointer, public :: stdin => NULL()
contains
  subroutine my_p(w)
    character(128) :: w
    call r(stdin,(/w/))
  end subroutine my_p
  subroutine r(ptr, io)
    use global
    type(point), pointer :: ptr
    character(128) :: io(:)
    if (associated (ptr)) call abort ()
    if (io(1) .ne. line) call abort ()
  end subroutine r
end module my_module

program main
  use global
  use my_module

  call option_stopwatch_s("hello ") 
  call p()                   
  call my_p(line)            

  call test_p()
  call test_my_p()
  call test_option_stopwatch()

contains

  subroutine option_stopwatch_s(a)
    character (*), intent(in) :: a
    character (len=len(a)) :: b

    b = 'hola! '
    call option_stopwatch_a((/a, b, 'goddag'/))
  end subroutine option_stopwatch_s 

  subroutine option_stopwatch_a(a)
    character (*) :: a(:)
    if (any(a .ne. (/'hello ', 'hola! ', 'goddag'/))) call abort()
  end subroutine option_stopwatch_a

  subroutine test_p()
    call p()
    print *, "Test p passed."
  end subroutine test_p

  subroutine test_my_p()
    call my_p(line)
    print *, "Test my_p passed."
  end subroutine test_my_p

  subroutine test_option_stopwatch()
    call option_stopwatch_s("hello ")
    call option_stopwatch_a((/"hello ", "hola! ", "goddag"/))
    print *, "Test option_stopwatch passed."
  end subroutine test_option_stopwatch

end program main