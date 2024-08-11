module soop_stars_class
  implicit none

  type :: soop_stars
    real, dimension(:), allocatable :: position, velocity
  contains
    procedure :: total
    procedure :: product
    generic :: operator(+) => total
    generic :: operator(*) => product
  end type soop_stars

contains
  type(soop_stars) function product(lhs, rhs)
    class(soop_stars), intent(in) :: lhs
    real, intent(in) :: rhs
    product%position = lhs%position * rhs
    product%velocity = lhs%velocity * rhs
  end function product

  type(soop_stars) function total(lhs, rhs)
    class(soop_stars), intent(in) :: lhs, rhs
    total%position = lhs%position + rhs%position
    total%velocity = lhs%velocity + rhs%velocity
  end function total
end module soop_stars_class

program main
  use soop_stars_class
  implicit none
  type(soop_stars) :: star1, star2, result

  ! Initialize star1 and star2 for testing
  star1%position = [1.0, 2.0, 3.0]
  star1%velocity = [4.0, 5.0, 6.0]
  star2%position = [0.5, 1.0, 1.5]
  star2%velocity = [2.0, 2.5, 3.0]

  ! Test total
  result = star1 + star2
  if (all(result%position == [1.5, 3.0, 4.5]) .and. all(result%velocity == [6.0, 7.5, 9.0])) then
    print *, "Total test passed."
  else
    print *, "Total test failed."
  end if

  ! Test product
  result = star1 * 2.0
  if (all(result%position == [2.0, 4.0, 6.0]) .and. all(result%velocity == [8.0, 10.0, 12.0])) then
    print *, "Product test passed."
  else
    print *, "Product test failed."
  end if
end program main