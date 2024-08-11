program statsort_test
  implicit none
  real :: data(5) = (/17.2, 18.1, 16.5, 18.3, 12.6/)
  real :: median, upperq, lowerq

  call bubble_sort(data, 5)
  print *, "Sorted dataset: ", data

  median = compute_median(data, 5)
  upperq = compute_quantile(data, 5, 0.75)
  lowerq = compute_quantile(data, 5, 0.25)

  print *, "The median is ", median
  print *, "The upper quartile is ", upperq
  print *, "The lower quartile is ", lowerq

contains

  subroutine bubble_sort(array, n)
    real, intent(inout) :: array(n)
    integer, intent(in) :: n
    integer :: i, j
    real :: temp
    do i = 1, n-1
      do j = 1, n-i
        if (array(j) > array(j+1)) then
          temp = array(j)
          array(j) = array(j+1)
          array(j+1) = temp
        end if
      end do
    end do
  end subroutine bubble_sort

  function compute_median(array, n) result(median)
    real, intent(in) :: array(n)
    integer, intent(in) :: n
    real :: median
    if (mod(n, 2) == 0) then
      median = 0.5 * (array(n / 2) + array(n / 2 + 1))
    else
      median = array((n + 1) / 2)
    end if
  end function compute_median

  function compute_quantile(array, n, q) result(quantile)
    real, intent(in) :: array(n)
    integer, intent(in) :: n
    real, intent(in) :: q
    real :: quantile
    integer :: idx
    idx = int(q * real(n + 1))
    quantile = array(max(1, min(idx, n)))
  end function compute_quantile

end program statsort_test