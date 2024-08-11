! Define subroutines first
subroutine sub1(sub)
      implicit none
      external sub
      interface
          subroutine sub(num)
              integer :: num
          end subroutine sub
      end interface
      call sub(1)
end subroutine sub1

subroutine sub2(num)
      integer :: num
      print *, num
end subroutine sub2

! Main program follows
program main
      implicit none
      external sub2
      call sub1(sub2)
end program main