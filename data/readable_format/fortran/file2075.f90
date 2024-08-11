program test_formrt
      implicit none
      double precision skew(2), rot(3,3)
      integer i, j

      ! Assuming nskdim is 2 for this example
      skew(1) = 0.5
      skew(2) = 0.6
      
      call formrt(skew, rot)
      
      print *, 'Rotation Matrix:'
      do i = 1, 3
         do j = 1, 3
            print *, 'rot(', i, ',', j, ') =', rot(i, j)
         end do
      end do

contains

      subroutine formrt(skew, rot)
      double precision skew(2), rot(3,3)
      double precision sina, cosa, sinb, cosb
      double precision zero
      zero = 0.0

      sina = sin(skew(1))
      cosa = cos(skew(1))
      sinb = sin(skew(2))
      cosb = cos(skew(2))
      rot(1,1) = cosa*cosb
      rot(2,1) = sina*cosb
      rot(3,1) = -sinb
      rot(1,2) = -sina
      rot(2,2) = cosa
      rot(3,2) = zero
      rot(1,3) = cosa*sinb
      rot(2,3) = sina*sinb
      rot(3,3) = cosb

      end subroutine formrt

end program test_formrt