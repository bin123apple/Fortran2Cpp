module maths_utils
  implicit none
  private
  public :: cds1, cds2

contains

  pure integer function cds1(nPoints, dim)
    integer, intent(in) :: nPoints, dim
    
    if (dim == 1) then
       cds1 = nPoints - 1
    else
       cds1 = nPoints
    end if
  end function cds1
  
  pure integer function cds2(nPoints, dim)
    integer, intent(in) :: nPoints, dim
    
    if (dim == 2) then
       cds2 = nPoints - 1
    else
       cds2 = nPoints
    end if
  end function cds2

end module maths_utils

program test_maths_utils
  use maths_utils
  implicit none

  print *, 'Testing cds1 and cds2'
  print *, 'cds1(5, 1) = ', cds1(5, 1) ! Expected output: 4
  print *, 'cds1(5, 2) = ', cds1(5, 2) ! Expected output: 5
  print *, 'cds2(5, 1) = ', cds2(5, 1) ! Expected output: 5
  print *, 'cds2(5, 2) = ', cds2(5, 2) ! Expected output: 4
end program test_maths_utils