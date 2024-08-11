program TestSortInt
  implicit none
  integer, allocatable :: arr(:)
  integer :: i, n

  n = 5
  allocate(arr(n))
  arr = (/4, 2, 5, 1, 3/)

  call sortint(n, arr)

  print *, "Sorted array:"
  do i = 1, n
      print *, arr(i)
  end do

  deallocate(arr)

contains

  subroutine sortint(n, arr)
    integer, intent(in) :: n
    integer, intent(inout) :: arr(n)
    integer :: i, j, a, temp

    do i = 2, n
      a = arr(i)
      j = i - 1
      do while (j > 0 .and. arr(j) > a)
        arr(j + 1) = arr(j)
        j = j - 1
      end do
      arr(j + 1) = a
    end do
  end subroutine sortint

end program TestSortInt