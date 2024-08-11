module m1
  contains
    subroutine s1(f)
      interface
        function f()
          integer f
        end function f
      end interface
      integer :: result
      result = f()
      print *, "s1 called with function result =", result
    end subroutine s1

    subroutine s2(x)
      integer :: x
      print *, "s2 called with x =", x
    end subroutine s2
end module m1

module func_mod
  contains
    integer function y()
      y = 1
    end function y

    integer function z()
      z = 1
    end function z

    integer function w()
      w = 1
    end function w

    integer function x()
      x = 1
    end function x
end module func_mod

program test
  use m1
  use func_mod
  implicit none

  call s1(y)
  call s1(z)
  call s1(w)
  call s1(x)
  call s2(x())

  print *, "y() =", y()
  print *, "z() =", z()
  print *, "w() =", w()
  print *, "x() =", x()
end program test