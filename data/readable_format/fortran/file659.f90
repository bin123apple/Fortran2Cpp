program test_fact
  implicit none
  integer :: i, expected, result

  do i = 1, 10
     expected = test_fact_expected(i)
     result = fact(i)
     if (result .ne. expected) then
        print *, 'Test failed for i =', i, 'Expected:', expected, 'Got:', result
        stop 1
     else
        print *, 'Test passed for i =', i, 'Expected:', expected, 'Got:', result
     end if
  end do

contains

  recursive function fact (x) result (res)
    implicit none
    integer, intent(in) :: x
    integer :: res
    if (x < 1) then
       res = 1
    else
       res = x * fact(x - 1)
    end if
  end function fact

  function test_fact_expected(x) result (res)
    implicit none
    integer, intent(in) :: x
    integer :: res
    select case(x)
    case(1)
       res = 1
    case(2)
       res = 2
    case(3)
       res = 6
    case(4)
       res = 24
    case(5)
       res = 120
    case(6)
       res = 720
    case(7)
       res = 5040
    case(8)
       res = 40320
    case(9)
       res = 362880
    case(10)
       res = 3628800
    case default
       res = -1  ! Invalid case
    end select
  end function test_fact_expected

end program test_fact