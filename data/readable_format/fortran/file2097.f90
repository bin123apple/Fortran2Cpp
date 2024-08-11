program testSub
      implicit none
      integer :: a(10), i
      call sub(a,10)
      do i = 1, 10
         if (a(i) .ne. i) then
            print *, 'Test failed at index:', i
            stop
         endif
      end do
      print *, 'All tests passed.'
      end

      subroutine sub(a,n)
      integer, dimension(n) :: a
      integer :: i
      do i = 1, n
        a(i) = i
      end do
      return
      end