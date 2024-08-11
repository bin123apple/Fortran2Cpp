module test
  implicit none

  type :: t
    procedure(ptr), pointer, nopass :: ppt
  end type t

  abstract interface
    function ptr() result(res)
      character(len=:), allocatable :: res
    end function ptr
  end interface

contains

  function deferred_len() result(res)
    character(len=:), allocatable :: res
    res = 'abc'
  end function deferred_len

  subroutine doIt()
    type(t) :: x
    character(:), allocatable :: temp
    x%ppt => deferred_len
    temp = deferred_len()
    if ("abc" /= temp) then
      call abort()
    else
      print *, "Fortran test passed."
    endif
  end subroutine doIt

end module test

program main
  use test
  call doIt()
end program main