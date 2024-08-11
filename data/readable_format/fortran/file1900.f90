module sum_module
contains
  function compute_sum(n) result(sum)
    implicit none
    integer, intent(in) :: n
    integer :: sum
    integer :: i

    sum = 0
    do i = 1, n
       sum = sum + i
    end do
  end function compute_sum
end module sum_module

program example
  use sum_module
  implicit none
  integer :: sum

  sum = compute_sum(10)
  print *, 'The sum is', sum
end program example